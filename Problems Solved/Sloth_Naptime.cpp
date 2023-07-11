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
    int n; cin >> n;
	vector<vector<int>> tree(n,vector<int>());
	for(int i=0;i<n-1;++i){
		int a,b; cin >> a >> b;
		a--,b--;
		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}	
	vector<vector<int>> UP(n,vector<int>(20));

	vector<int> vis(n);
	vector<int> dpt(n);
	function<void(int)> dfs = [&](int v){
		if(vis[v]) return;
		vis[v] = 1;
		for(auto c : tree[v]){
			if(vis[c]) continue;
			dpt[c] = dpt[v] + 1;
			UP[c][0] = v;
			dfs(c);
		}
	};
	dfs(0);
	for(int k=0;k<19;++k){
		for(int i=0;i<n;++i){
			UP[i][k+1] = UP[ UP[i][k] ][k];
		}
	}

	function<int(int,int)> find_lca = [&](int a,int b){
		if(dpt[a]>dpt[b]) swap(a,b);
		int k = dpt[b]-dpt[a];
		for(int i=19;i>-1;--i){
			if((k>>i)&1){
				b = UP[b][i];
			}
		}
		if(a==b) return a;
		for(int i=19;i>-1;--i){
			if(UP[a][i]!=UP[b][i]){
				a = UP[a][i];
				b = UP[b][i];
			}
		}
		return UP[a][0];
	};

	int q; cin >> q;
	while(q--){
		int a,b,c; cin >> a >> b >> c;
		a--,b--;
		int lca = find_lca(a,b);
		int up = dpt[a]-dpt[lca];
		int down = dpt[b]-dpt[lca];
		int total_dis = up+down;
		if(total_dis<=c){
		    cout << b+1 << endl;
		}else if(up<=c){
			int tup = total_dis-c;
			for(int i=19;i>-1;--i){
				if((tup>>i)&1){
					b = UP[b][i];
				}
			}
			cout << b+1 << "\n";
		}else{
			for(int i=19;i>-1;--i){
				if((c>>i)&1){
					a = UP[a][i];
				}
			}
			cout << a+1 << "\n";
		}
	}
}
