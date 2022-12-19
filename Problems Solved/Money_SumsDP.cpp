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
	ll n; cin >> n;
	vll coins(n);
	ll sum = 0;
	for(int i=0;i<n;++i){
		cin >> coins[i];
		sum+=coins[i];
	}
	vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
	ll ans = 0;
	dp[0][0] = 1;
	for(int c=1;c<=n;++c){
		for(int x = 0;x<=sum;++x){
			if(x>=coins[c-1]) dp[c][x]=(dp[c][x]|dp[c-1][x-coins[c-1]]);
			dp[c][x] = (dp[c][x]|dp[c-1][x]);
		}
	}	    
	for(int i=1;i<=sum;++i){
		if(dp[n][i]) ans++;
	}
	cout << ans << endl;
	for(int i=1;i<=sum;++i) if(dp[n][i]) cout << i << " ";
	cout << endl;
}
