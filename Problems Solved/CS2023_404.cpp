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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    // ll strs = 0;
    // for(int i=0;i<n;++i) strs+=(s[i]=='*');
    // vector<vector<vll>> dp(n+1,vector<vll>(4,vll(4)));
    // dp[0][0][0] = 1;
    // for(int i=0;i<n;++i){
    // 	for(int j=0;j<4;++j){
    // 		for(int k=0;k<4;++k){
    // 			if(!dp[i][j][k]) continue;
    // 			dp[i+1][j][k] = (dp[i+1][j][k]+dp[i][j][k])%MOD;
    // 			char tmp='*';
    // 			if(j==0||j==2) tmp = '4';
    // 			else if(j==1) tmp = '0';
    // 			if(j<3&&(s[i]=='*'||s[i]==tmp)){
    // 				dp[i+1][j+1][k+(s[i]=='*')] = (dp[i+1][j+1][k+(s[i]=='*')]+dp[i][j][k])%MOD;
    // 			}
    // 		}
    // 	}
    // }
    // ll ans = 0;
    // for(int i=0;i<4;++i){
    // 	if(strs>i-1){
    // 		ans+=(dp[n][3][i]*binpow(2,strs-i,MOD))%MOD;
    // 		ans%=MOD;
    // 	}
    // }
    // cout << ans << endl;
    vector<vector<ll>> dp(n+1,vector<ll>(3)); // 4,40,404
    ll m=1;
    for(int i=0;i<n;++i){
        if(s[i]=='4'){
            dp[i+1][0] = (dp[i][0] + m)%MOD;
            dp[i+1][1] = dp[i][1]%MOD;
            dp[i+1][2] = (dp[i][2] + dp[i][1])%MOD;
        }else if(s[i]=='0'){
            dp[i+1][1] = (dp[i][1] + dp[i][0])%MOD;
            dp[i+1][0] = dp[i][0];
            dp[i+1][2] = dp[i][2];
        }else{
            dp[i+1][0] = (dp[i][0]*2)%MOD;
            dp[i+1][1] = (dp[i][1]*2)%MOD;
            dp[i+1][2] = (dp[i][2]*2)%MOD;

            dp[i+1][0] = (dp[i+1][0]+ m)%MOD;
            dp[i+1][1] = (dp[i+1][1] + dp[i][0])%MOD;
            dp[i+1][2] = (dp[i+1][2] + dp[i][1])%MOD;

            m = (m*2)%MOD;
        }
    }
    cout << dp[n][2] << endl;
}
