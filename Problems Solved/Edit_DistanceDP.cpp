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
	string a,b; cin >> a >> b;
	ll n = siz(a),m = siz(b);
	vector<vll> dp(n+1,vll(m+1,INF));
	dp[0][0] = 0;
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i>0) dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
			if(j>0) dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
			if(i>0&&j>0) dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1]));
		}
	}	    
	cout << dp[n][m] << endl;
}
