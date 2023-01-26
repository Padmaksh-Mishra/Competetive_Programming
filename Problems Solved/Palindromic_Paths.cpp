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
	vector<string> s(n);
	for(int i=0;i<n;++i){
		cin >> s[i];
	}	    
	int i,j;
	vector<vector<vll>> dp(n+1,vector<vll>(n+1,vll(26)));
	dp[1][1][0] = 1;
	for(i=0;i<(n+1)/2 + 1;++i){
		for(j=0;j<(n+1)/2 + 1;++j){
			for(int k=0;k<26;++k){
				if(i==0||j==0){
					dp[i][j][k] = 0;
					continue;
				}
				dp[i][j][s[i-1][j-1]-'A']+=dp[i-1][j][k];
				dp[i][j][s[i-1][j-1]-'A']+=dp[i][j-1][k];
			}
		}
	}
	for(;i<n+1;++i){
		for(;j<n+1;++j){
			ll dis = n-i+n-j;
			for(int k=0;k<dis+1;++k){
				dp[i][j][s[i-1][j-1]-'A']+=dp[dis-k][k][s[i-1][j-1]-'A'];
			}
		}
	}
	cout << dp[n][n][0] << endl;
}
