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

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vector<vll> dp(n+1,vll(2,-1));
    fill(all(dp[n]),0);
    for(int i=0;i<n;++i){
        vector<bool> tmp(n);
        if(dp[i][0]==-1){
            tmp[i] = (s[i]=='1');
            for(int j=i+1;j<n;++j){
                // if(dp[j][s[j]=='1']!=-1) break;
                tmp[j] = !(tmp[j-1]&(s[j]=='1'));
            }
            if(dp[n-1][(s[n-1]=='1')]==-1) dp[n-1][(s[n-1]=='1')] = tmp[n-1];
            for(int j=n-2;j>i-1;--j){
                if(dp[j][(s[j]=='1')]!=-1) break;
                dp[j][(s[j]=='1')] = dp[j+1][(s[j+1]=='1')] + tmp[j];
            }
        }
        if(dp[i][1]==-1){
            tmp[i] = (s[i]=='1');
            for(int j=i+1;j<n;++j){
                tmp[j] = !(tmp[j-1]&(s[j]=='1'));
            }
            dp[n-1][(s[n-1]=='1')] = tmp[n-1];
            for(int j=n-2;j>i-1;--j){
                dp[j][(s[j]=='1')] = dp[j+1][(s[j+1]=='1')] + tmp[j];
            }
        }
    }
    // for(int i=0;i<n;++i){
    //     cout << dp[i][0] <<  " " << dp[i][1] << endl;
    // }
    ll ans = 0;
    for(int i=0;i<n;++i){
        ans+=dp[i][(s[i]=='1')];
    }
    cout << ans << endl;
}