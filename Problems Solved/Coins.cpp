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
	vector<double> p(n);
	for(int i=0;i<n;++i){
		cin >> p[i];
	}	    
	vector<vector<double>> dp(n+1,vector<double>(n+1));
	dp[0][0] = 1;
	for(int i=0;i<n+1;++i){
		for(int c=0;c<n+1;++c){
			if(i<n) dp[i+1][c] += dp[i][c]*(1-p[i]);
			if(i<n&&c<i+1) dp[i+1][c+1] += dp[i][c]*p[i];
		}
	}
	double totprob = 0;
	for(int i=0;i<(n+1)/2;++i){
		totprob+=dp[n][n-i];
	}
	cout << setprecision(10) <<  totprob << endl;
}
