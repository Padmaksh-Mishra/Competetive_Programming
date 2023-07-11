# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (ll)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()
# define YES cout<<"Yes"<<endl
# define NO cout<<"No"<<endl

//Namespaces
using namespace __gnu_pbds;
using namespace std;

//Templates
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>; //less_equal=ms can have duplicates
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(K): Kth element in a Set (counting from zero).

//Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const ll N = 2e5 + 1;   

//For fileIO
void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

//bexpo
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve();

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    //setIO("sublime");        
    ll TC = 1;
    // cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    int n,m; cin >> n >> m;
	vector<vector<pair<int,int>>> tree(n,vector<pair<int,int>>());
	for(int i=0;i<n-1;++i){
		int a,b,w; cin >> a >> b >> w;
		a--,b--;
		tree[a].emplace_back(make_pair(b,w));
		tree[b].emplace_back(make_pair(a,w));
	}	
	vector<vector<pair<int,int>>> UP(n,vector<pair<int,int>>(20));

	vector<int> vis(n);
	vector<int> dpt(n);
	function<void(int)> dfs = [&](int v){
		if(vis[v]) return;
		vis[v] = 1;
		for(auto c : tree[v]){
			if(vis[c.f]) continue;
			dpt[c.f] = dpt[v] + 1;
			UP[c.f][0].f = v;
			UP[c.f][0].s = c.s;
			dfs(c.f);
		}
	};
	dfs(0);
	for(int k=0;k<19;++k){
		for(int i=0;i<n;++i){
			UP[i][k+1].f = UP[ UP[i][k].f ][k].f;
			UP[i][k+1].s = min(UP[ UP[i][k].f ][k].s,UP[i][k].s);
		}
	}

	function<int(int,int)> find_lca = [&](int a,int b){
		int mini = 2e9;
		if(dpt[a]>dpt[b]) swap(a,b);
		int k = dpt[b]-dpt[a];
		for(int i=19;i>-1;--i){
			if((k>>i)&1){
				mini = min(mini,UP[b][i].s);
				b = UP[b][i].f;
			}
		}
		if(a==b) return mini;
		for(int i=19;i>-1;--i){
			if(UP[a][i].f!=UP[b][i].f){
				mini = min(mini,UP[b][i].s);
				mini = min(mini,UP[a][i].s);
				a = UP[a][i].f;
				b = UP[b][i].f;
			}
		}
		mini = min({mini,UP[a][0].s,UP[b][0].s});
		return mini;
	};

	int q; cin >> q;
	while(q--){
		int a,b,c; cin >> a >> b;
		a--,b--;
		int mini = find_lca(a,b);
		cout << mini << endl;
	}
}
