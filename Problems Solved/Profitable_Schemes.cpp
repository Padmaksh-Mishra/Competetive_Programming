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
    ll minProfit; cin >> minProfit;
    vll profit(n),group(n);
    for(int i=0;i<3;++i) cin >> profit[i];
    for(int i=0;i<3;++i) cin >> group[i];
    vector<pll> t;	
	for(int i=0;i<3;++i){
		t.emplace_back(make_pair(group[i],profit[i]));
	}
	sort(all(t));
    vector<vll> dp(n+1,vll(10000+1));
    dp[0][0] = 0;
	for(int i=0;i<3+1;i++){
		for(int j=0;j<n+1;++j){
            // deb(t[i].s);
			// if(i<3) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(i<3 && j+t[i].f<n+1) dp[i+1][j+t[i].f]=max(dp[i+1][j+t[i].f],dp[i][j]+t[i].s);
            cout << dp[i][j] << " ";
		}
        cout << endl;
	}
	ll ans = 0;
	for(int i=1;i<n+1;++i){
		if(dp[3][i]>minProfit-1){
            deb(dp[3][i]);
            ans++;
        }
	}
	cout << ans << endl;
}
