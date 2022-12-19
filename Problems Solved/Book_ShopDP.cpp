# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,x; cin >> n >> x;
	vector<vector<int>> dp(n+1,vector<int>(x+1));
	vector<int> price(n),pages(n);
	
	for(int i=0;i<n;++i) cin >> price[i];
	for(int i=0;i<n;++i) cin >> pages[i];
	for(int i=1;i<=n;++i){
		for(int p = 1;p<=x;++p){
			if(p>=price[i-1]){
				dp[i][p] = max(dp[i][p],dp[i-1][p-price[i-1]]+pages[i-1]);
			}
			dp[i][p] = max(dp[i][p],dp[i-1][p]);
		}
	}
	cout << dp[n][x] << endl;
}
