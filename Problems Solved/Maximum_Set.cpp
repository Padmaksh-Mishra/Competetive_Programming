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
const ll MOD = 998244353;
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
    ll l,r; cin >> l >> r;
    ll tmp = l;
    ll a = 0;
    while(tmp<r+1){
    	a++;
    	tmp<<=1ll;
    }
    ll m = 0,ans = 0;
    if(a>1) m = (1ll<<(a-2ll));
    if(m==0){
    	ans = r-l+1;
    }else{
    	ll ns3 = max(0ll,((r/(3ll*m)) - l + 1)%MOD);
	    ll ns2 = max(0ll,((r/(2ll*m)) - l + 1)%MOD);
	    ans = 1;
	    if(a>1) ans = (ns3)*(a-1);
	    ans%=MOD;
	    ans = (ans+ns2)%MOD;
    }
    cout << a << " " << ans << endl;
}
