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

// Doing something good 

void solve(){
    ll n,m; cin >> n >> m;
    vll v(n+m+1,0),p(n+m+1,1);
    vll org(n+1);
    vector<bool> op(n+m+1,false);
    for(int i=1;i<n+1;++i){
    	ll tmp; cin >> tmp;
    	op[tmp] = true;
    	p[tmp] = 0;
    	org[i] = tmp;
    }
    for(int i=2;i<m+2;++i){
    	ll a,b;
    	cin >> a >> b;
    	ll pos = a;
    	a = org[a];
    	op[a] = false;
    	p[a] = i;
    	if(!op[b]) v[b]+=(i-p[b]);
    	op[b] = true;
    	org[pos] = b;
    }
    for(int i=1;i<n+m+1;++i){
    	if(!op[i]){
    		v[i]+=(m+2-p[i]);
    	}
    }
    ll ans = 0;
    ll pr = ((m*(m+1ll))/2);
    for(int i=1;i<n+m+1;++i){
    	ll tmp = (pr - ((v[i])*(v[i]-1))/2);
    	ans+=tmp;
    }
    cout << ans << endl;
}
