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
	ll n,k,d; cin >> n >> k >> d;
	vll a(n+1);
	for(int i=1;i<=n;++i) cin >> a[i];
	//Editorial
	vector<vector<vll>> dp(n+1,vector<vll>(k+1,vll(d,-1)));	 
	dp[0][0][0] = 0;   
	for(int s=0;s<n;++s){
		for(int t=0;t<=k;++t){
			for(int r=0;r<d;++r){
				if(dp[s][t][r]==-1) continue;
				if(t!=k) dp[s+1][t+1][(r+a[s+1])%d] = max(dp[s+1][t+1][(r+a[s+1])%d],dp[s][t][r] + a[s+1]);
				dp[s+1][t][r] = max(dp[s+1][t][r],dp[s][t][r]);
			}
		}
	}
	cout << dp[n][k][0] << endl;

	//ON MY OWN
	// vector<vector<set<ll>>> dp(n+1,vector<set<ll>>(n+1)); //dp[seen][used] = sum;
	// for(int s = 0;s<=n;++s){
	// 	for(int u=0;u<=s;++u){
	// 		if(u==0){
	// 			dp[s][u].insert(0);
	// 			continue;
	// 		}
	// 		for(auto val : dp[s-1][u-1]){
	// 			dp[s][u].insert(val+a[s]);
	// 		}
	// 		for(auto val : dp[s-1][u]){
	// 			dp[s][u].insert(val);
	// 		}
	// 	}
	// }
	// ll ans = -1;
	// for(auto val : dp[n][k]){
	// 	//deb(val);
	// 	if(val%d==0){
	// 		ans = val;
	// 	}
	// }
	// cout << ans << endl;
}
