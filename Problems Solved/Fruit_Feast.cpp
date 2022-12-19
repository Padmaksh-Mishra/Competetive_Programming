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
	ll t,a,b; cin >> t >> a >> b;
	vector<vector<bool>> dp(2,vector<bool>(t+1));
	dp[0][0] = 1;
	for(int i=0;i<=1;++i){	
		for(int s=0;s<=t;++s){ 
			if(s>=a){
				dp[i][s] = (dp[i][s]|dp[i][s-a]);
			}
			if(s>=b){
				dp[i][s] = (dp[i][s]|dp[i][s-b]);
			}
			if(i==0) dp[1][s/2] = dp[0][s];
		}	    
	}
	
	for(ll i=t;i>=0;--i){
		if(dp[1][i]){
			cout << i << endl;
			return;
		}
	}
}
