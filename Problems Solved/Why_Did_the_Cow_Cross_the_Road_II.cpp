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
	ll n; cin >> n;
	vll l(n+1),r(n+1);
	vector<vll> dp(n+1,vll(n+1));
	for(int i=0;i<n;++i){
		cin >> l[i];
	}
	for(int i=0;i<n;++i){
		cin >> r[i];
	}
	for(int i=0;i<n+1;++i){
		for(int j=0;j<n+1;++j){
			if(i<n) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j<n) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
			if(i<n&&j<n) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + (abs(l[i]-r[j])<5));
		}
	}
	cout << dp[n][n] << endl;

}
