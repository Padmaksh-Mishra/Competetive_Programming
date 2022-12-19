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
	ll H,G; cin >> H >> G;
	vector<pll> h(H),g(G);
	vector<vector<vll>> dp(H+1,vector<vll>(G+1,vll(2,INF)));
	for(int i=0;i<H;++i){
		cin >> h[i].f >> h[i].s;
	}
	for(int i=0;i<G;++i){
		cin >> g[i].f >> g[i].s;
	}
	auto dist = [](pll a,pll b)->ll{
		return ((a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s));
	};
	dp[1][0][0] = 0;
	for(int i=1;i<=H;++i){
		for(int j=0;j<=G;++j){
			if(i>1) dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][0] + dist(h[i-1],h[i-2]));
			if(i>0&&j>0) dp[i][j][0] = min(dp[i][j][0],dp[i-1][j][1] + dist(h[i-1],g[j-1]));
			if(i>0&&j>0) dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][0] + dist(g[j-1],h[i-1]));
			if(j>1) dp[i][j][1] = min(dp[i][j][1],dp[i][j-1][1] + dist(g[j-1],g[j-2]));		
		}
	}	
	cout << dp[H][G][0] << endl;    
}
