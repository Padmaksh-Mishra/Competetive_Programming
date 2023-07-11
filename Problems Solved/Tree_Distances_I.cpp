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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
pll diameter(vector<vll> &tree,ll n){
	vll dpt(n);
	function<void(ll,ll)> dfs = [&](ll v,ll p){
    	for(auto c : tree[v]){
    		if(c==p) continue;
    		dpt[c] = dpt[v] + 1;
    		dfs(c,v);
    	}
    };
    dfs(0,-1);
    pll ans;
    ans.f = max_element(all(dpt))-dpt.begin();
    fill(all(dpt),0);
    dfs(ans.f,-1);
    ans.s = max_element(all(dpt)) - dpt.begin();
    return ans;
}

void solve(){
    ll n; cin >> n;
    vector<vll> tree(n,vll());
    vector<vll> bl(n,vll(20));
    vll dpt(n);

    dpt[0] = 0;

    for(int i=0;i<n-1;++i){
    	ll a,b; cin >> a >> b;
    	a--,b--;
    	tree[a].emplace_back(b);
    	tree[b].emplace_back(a);
    }

    function<void(ll,ll)> dfs = [&](ll v,ll p){
    	for(auto c : tree[v]){
    		if(c==p) continue;
    		bl[c][0] = v;
    		dpt[c] = dpt[v] + 1;
    		dfs(c,v);
    	}
    };
    dfs(0,-1);

    for(int k=0;k<19;++k){
    	for(int i=0;i<n;++i){
    		bl[i][k+1] = bl[ bl[i][k] ][k];
    	}
    }
    pll dia = diameter(tree,n);
    ll po = dia.f;
    ll pt = dia.s;
    vll ans(n);

    function<ll(ll,ll)> lca = [&](ll a,ll b){
    	if(dpt[a]<dpt[b]) swap(a,b);
    	ll tmp = dpt[a]-dpt[b];
    	for(int i=19;i>-1;--i){
    		if((tmp>>i)&1) a = bl[a][i];
    	}
    	if(a==b) return a;
    	for(int i=19;i>-1;--i){
    		if(bl[a][i]!=bl[b][i]){
    			a = bl[a][i];
    			b = bl[b][i];
    		}
    	}
    	return bl[a][0];
    };

    for(int i=0;i<n;++i){
    	ans[i] = max(dpt[po]+dpt[i]-2*dpt[lca(po,i)],dpt[pt]+dpt[i]-2*dpt[lca(pt,i)]);
    }
    for(auto val : ans) cout << val << " ";
    cout << endl;
}
