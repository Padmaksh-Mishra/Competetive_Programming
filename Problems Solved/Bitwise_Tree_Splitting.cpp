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
const ll MAXAND = (1ll<<32)-1;

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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    vll tree[100001];
    vll val(n);
    for(int i=0;i<n;++i){
    	cin >> val[i];
    }
    vector<pll> edges;
    for(int i=0;i<n-1;++i){
    	ll a,b; cin >> a >> b;
    	tree[a].emplace_back(b);
    	tree[b].emplace_back(a);
    	edges.emplace_back(make_pair(a,b));
    }
    vll par(n);
    vll ands(n,MAXAND),andr(n,MAXAND);
    par[0]=-1;
    // for(int i=0;i<n;++i) cout << ands[i] << endl;
    function<void(ll)> dfs = [&](ll v){
    	andr[v] &= val[v];
    	for(auto c : tree[v]){
    		if(c==par[v]) continue;
    		par[c] = v;
    		dfs(c);
    		// deb(ands[c]);
    		(ands[v]&=ands[c]);
    		(andr[c]&=andr[v]);
    	}
    	(ands[v]&=val[v]);
    };
    dfs(0);
    ll ans = 0;
    for(auto edge : edges){
    	ll a = edge.f,b = edge.s;
    	if(b==par[a]) swap(a,b);
    	ll tmp = MAXAND;
    	if(siz(tree[a])>1){
    		for(auto c : tree[a]){
    			if(c!=b){
    				tmp&=ands[c];
    				break;
    			}
    		}
    	}
    	if(a!=0&&siz(tree[0]>1)){
    		for(auto c : tree[0]){
    			if(c!=b){
    				tmp&=ands[c];
    				break;
    			}
    		}
    	}
    	tmp&=val[a];
    	tmp&=andr[a];
    	if(ands[b]==tmp) ans++;
    }
    cout << ans << endl;
}
