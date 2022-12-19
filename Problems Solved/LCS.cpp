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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	string text1,text2; cin >> text1 >> text2;
	ll n = siz(text1);
	ll m = siz(text2);
	vector<vll> dp(n+1,vll(m+1));
	for(int i=0;i<=n;++i){
		for(int j=0;j<=m;++j){
			if(i<n) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j<m) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
			if(i<n&j<m) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+(text1[i]==text2[j]));
		}
	}
	cout << dp[n][m] << endl;	    
}
