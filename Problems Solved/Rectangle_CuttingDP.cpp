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
	ll a,b; cin >> a >> b;
	vector<vll> dp(a+1,vll(b+1,INF));
	for(int i=0;i<a+1;++i){
		for(int j=0;j<b+1;++j){
			if(i==j){
				dp[i][j] = 0;
			}
			for(int c=1;c<min(a,b);++c){
				if(i-c>0) dp[i][j] = min(dp[i][j],dp[i-c][j]+dp[c][j]+1);
				if(j-c>0) dp[i][j] = min(dp[i][j],dp[i][j-c]+dp[i][c]+1);
			}
		}
	}	    
	cout << dp[a][b] << endl;
}
