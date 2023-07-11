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
ll binpow(ll a, ll b, ll m=MOD) {
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
    ll n; cin >> n;
    string s; cin >> s;
    vector<vector<ll>> dp(n+1,vector<ll>(3)); // a,ab,abc ----> dp[i][k] i=indx till counted k=state of strings counted
    ll m=1;
    for(int i=0;i<n;++i){
        if(s[i]=='a'){
            dp[i+1][0] = (dp[i][0] + m)%MOD;
            dp[i+1][1] = (dp[i][1])%MOD;
            dp[i+1][2] = (dp[i][2])%MOD;
        }else if(s[i]=='b'){
            dp[i+1][1] = (dp[i][1] + dp[i][0])%MOD;
            dp[i+1][0] = (dp[i][0])%MOD;
            dp[i+1][2] = (dp[i][2])%MOD;
        }else if(s[i]=='c'){
            dp[i+1][2] = (dp[i][2] + dp[i][1])%MOD;
            dp[i+1][1] = (dp[i][1])%MOD;
            dp[i+1][0] = (dp[i][0])%MOD;
        }else {
            dp[i+1][0] = (dp[i][0]*3)%MOD;
            dp[i+1][1] = (dp[i][1]*3)%MOD;
            dp[i+1][2] = (dp[i][2]*3)%MOD;

            dp[i+1][0] = (dp[i+1][0] + m)%MOD;

            dp[i+1][1] = (dp[i+1][1] + dp[i][0])%MOD;

            dp[i+1][2] = (dp[i+1][2] + dp[i][1])%MOD;

            m = (m*3)%MOD;
        }
    }
    cout << dp[n][2] << endl;
}
