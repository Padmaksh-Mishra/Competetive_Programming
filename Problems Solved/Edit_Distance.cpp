# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
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
	string a,b; cin >> a >> b;
	ll n = siz(a);
	ll m = siz(b);
	vector<vll> dp(5001,vll(5001,INF));
	dp[0][0] = 0;
	for(int i=0;i<n+1;++i){
		for(int j=0;j<m+1;++j){
			if(i<n) dp[i+1][j] = min(dp[i+1][j],dp[i][j] + 1);
			if(i<n&&j<m) dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + (a[i]!=b[j]));
			if(j<m) dp[i][j+1] = min(dp[i][j+1],dp[i][j] + 1);
		}
	}	    
	cout << dp[n][m] << endl;
}
