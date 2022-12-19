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
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll m; cin >> m;
	vector<vll> coins(2,vll(m+1));
	// vector<vll> dp(2,vll(m+1));
	// ll sum = 0;
	for(int i=0;i<2;++i){
		for(int j=1;j<=m;++j){
			cin >> coins[i][j];
		}
	}
	// dp[0][0] = coins[0][0];
	// for(int i=1;i<=m;++i){
	// 	dp[0][i] = dp[0][i-1] + coins[0][i]	;
	// 	dp[1][i] = dp[0][i] + coins[1][i];
	// 	dp[1][i] = max(dp[1][i],dp[1][i-1] + coins[1][i]);	
	// }	    
	// cout << sum - dp[1][m] << endl;
	vll stop(m+1);
	vll sdown(m+1);
	for(int i=1;i<=m;++i){
		stop[i] = stop[i-1] + coins[0][i];
	}
	for(int i=1;i<=m;++i){
		sdown[i] = sdown[i-1] + coins[1][i];
	}
	ll ans = 0;
	for(int i=1;i<=m;++i){
		ans = max(ans,min(stop[m]-stop[i],sdown[i]-sdown[0]));
	}
	cout << ans << endl;
}
