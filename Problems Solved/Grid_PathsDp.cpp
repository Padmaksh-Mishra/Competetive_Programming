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
	ll n; cin >> n;
	vector<string> v(n);
	vector<vll> dp(n,vll(n,0));
	for(int i=0;i<n;++i){
		cin >> v[i];
	}	    
	dp[0][0] = (v[0][0]=='.');
	for(int i=0;i<=n-1;++i){
		for(int j=0;j<=n-1;++j){
			if(v[i][j]=='*') continue;
			if(i<n-1&&v[i+1][j]!='*') dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
			if(j<n-1&&v[i][j+1]!='*') dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
		}
	}
	cout << dp[n-1][n-1]%MOD << endl;
}
