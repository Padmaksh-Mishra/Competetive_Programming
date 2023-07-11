# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define vpll vector<pll>
# define all(x) (x).begin(), (x).end()

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
const int N = 2e5 + 1;   

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

class SegmentTree {
public:
    SegmentTree(ll n, const vector<ll>& a) : n(n),t(2*N) {
        for (int i = 0; i < n; i++) {
            t[i + n] = a[i];
        }
    }

    void printLeves(){
        for(int i=n;i<(n<<1);++i){
            cout << t[i] << " ";
        }
        cout << endl;
    }

    // What operation you want to perform on tree (default is add)
    ll combine(ll a,ll b){
        return (a^b);
    }
    //CAUTION: Don't forget to build the tree
    void build() {
        for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1],t[i<<1|1]);
    }

    //This code is for modification of an element
    void modify(ll p, ll value) {
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = combine(t[p] , t[p^1]);
    }

    //Access the entire interval
    ll query(ll l, ll r) {    //r is excluded
        ll res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res = combine(res,t[l++]);
            if (r&1) res = combine(res,t[--r]);
        }
        return res;
    }
private:
    const ll n;
    vector<ll> t;
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

// Doing something good 

void solve(){
    ll n,q; cin >> n >> q;
    vll t(n);
    for(int i=0;i<n;++i){
    	cin >> t[i];
    }
    SegmentTree tree(n,t);
    tree.build();
    while(q--){
    	ll l,r; cin >> l >> r;
    	cout << tree.query(--l,r) << endl;
    }
}
