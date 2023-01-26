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
	ll h,w; cin >> h >> w;
	vector<string> grid(h);
	for(int i=0;i<h;++i){
		cin >> grid[i];
	}	    
	vector<vll> dp(h,vll(w));
	dp[0][0] = 1;
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			if(i+1<h) dp[i+1][j] = (dp[i+1][j]+dp[i][j]*(grid[i+1][j]=='.'))%MOD;
			if(j+1<w) dp[i][j+1] = (dp[i][j+1]+dp[i][j]*(grid[i][j+1]=='.'))%MOD;
		}
	}
	cout << (dp[h-1][w-1])%MOD << endl;
}
