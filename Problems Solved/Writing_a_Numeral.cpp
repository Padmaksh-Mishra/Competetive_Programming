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
const ll MOD = 998244353;
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
ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        ll q = A / M;
        ll t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}
void solve(){
    ll q; cin >> q;
    string s="1";
    vll ans(q+1);
    vll expos(q+1);
    ll val = 1;
    for(int i=0;i<q+1;++i){
    	expos[i] = (val%MOD);
    	val*=10;
    }
    ll start = 0;
    ans[0]=1;
    for(int i=0;i<q;++i){
    	ll t; cin >> t;
    	if(t==1){
    		char x; cin >> x;
    		s.push_back(x);
    		ans[i+1] = (ans[i]*10)%MOD;
    		// deb(ans[i+1]);
    		ans[i+1]+=(x-'0');
    		ans[i+1] = (ans[i+1]%MOD);
    		// deb(i+1);
    	}else if(t==2){
    		ll tmp = (s[start]-'0');
    		tmp*=(expos[siz(s)-start-1]);
    		ans[i+1]=(ans[i]-tmp)%MOD;
    		start++;
    	}
    	else{
    		ans[i+1] = ans[i];
    		cout << ans[i] << endl;
    	}
    }
}
