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
	ll sum = n*(n+1)/2;
	vector<vector<ll>> dp(n+1,vector<ll>(sum+1));
	ll ans = 0;
	dp[0][0] = 1;
	for(int c=1;c<n;++c){		//atleast 1 element dusre set ke liye chod do
		for(int x = 0;2*x<=sum;++x){
			if(x>=c) dp[c][x] += dp[c-1][x-c],dp[c][x]%=MOD;
			dp[c][x] += dp[c-1][x];
			dp[c][x]%=MOD;
		}
	}	    
	cout << ((sum&1)==0)*dp[n-1][sum/2] << endl;
}
