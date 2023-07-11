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



/* 
Without the small->large merging the time O(n) and also without the path compression but only small->large uinon
the time is O(logn) [true for revese also].
So for a better time complexity we need both of these optimizations leading to O(log*h)

log*h is the number of times I have to apply log to get a number smaller than 1

eg h = 2^65536

2^65536 -> 2^16 -> 2^4 -> 2^2 -> 2^1 -> 1 -> 0    6 times even for such a huge number (overflow in calculator)

so we consider it constant for sets of practical sizes

We can also store the results of all assosicative operations of sets using dsu
*/

class DSU {
public:
    DSU(ll n) {
        parent.resize(n+1);
        size.resize(n+1);
        comb.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            size[i] = 1;
            comb[i] = 0;
        }
    }
    // What operation you want to perform on tree (default is none) !!! only associ ops
    void combine(ll a,ll b){
    	a = get(a);
    	comb[a]+=b;
    }

    ll get(ll x) {
        if (parent[x] == x) return x;
        return parent[x]=get(parent[x]);
    }

    bool merge(ll x,ll y){		// union by size
    	ll px = get(x);
    	ll py = get(y);
    	if(px==py) return false;
    	if(size[px]>size[py]) swap(px,py);
    	parent[px] = py;
    	size[py] += size[px];
    	comb[px]-=comb[py];
    	return true;
    }

    ll result(ll p){
        ll ans = 0;
    	while(parent[p]!=p){
            ans+=comb[p];
            p = parent[p];
        }
        return ans+comb[p];
    }

private:
	vector<ll> parent;
    vector<ll> size;
    vll comb;
};


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

void solve(){
    ll n,m; cin >> n >> m;
    DSU dsu(n);
    while(m--){
    	string op; cin >> op;
    	if(op=="add"){
    		ll a,b; cin >> a >> b;
    		dsu.combine(a,b);
    	}else if(op=="join"){
    		ll a,b; cin >> a >> b;
    		dsu.merge(a,b);
    	}else{
    		ll v; cin >> v;
    		cout << dsu.result(v) << endl;
    	}
    }
}
