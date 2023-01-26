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
	vector<vector<ll>> ok(n+1,vector<ll>(n+1));
	for(int i=1;i<n+1;++i){
		for(int j=1;j<n+1;++j){
			cin >> ok[i][j];
		}
	}
	vll dp(1<<n);
	dp[0] = 1;
	for(int s=0;s<(1<<n);++s){
		for(int m=1;m<n+1;++m){
			for(int w=1;w<n+1;++w){
				if(!(s&(1<<(w-1)))) continue;
				if(ok[m][w]) dp[s] += dp[s^(1<<(w-1))];
			}
		}
	}	    
	cout << dp[(1<<n)-1] << endl;
}
