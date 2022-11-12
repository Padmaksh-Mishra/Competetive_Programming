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

const ll MOD = 1e14 +7;
const int N = 1e5 + 1;

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
ll dp[5001][5001];
void solve(){
	string s,t; cin >> s >> t;
	ll n,m; 
	n=s.size();
	m=t.size();
	
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			dp[i][j] = MOD;
		}
	}    
	dp[0][0]=0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i) {
				dp[i][j] = min(dp[i-1][j]+1,dp[i][j]);
			}
			if(j) {
				dp[i][j] = min(dp[i][j-1]+1,dp[i][j]);
			}
			if(i&&j) {
				dp[i][j] = min(dp[i-1][j-1]+(s[i-1]!=t[j-1]),dp[i][j]);
			}
		}
	}
	cout << dp[n][m] << endl;
}
