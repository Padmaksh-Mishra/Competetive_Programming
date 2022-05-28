//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	int ips[n+1];
	for(int i=1;i<n+1;i++) cin >> ips[i];
	int dp[n+1];
	dp[0] = 0;
	dp[n] = 0;
	dp[n-1] = abs(ips[n]-ips[n-1]);
	dp[n-2] = min(abs(ips[n-1]-ips[n-2])+dp[n-1],abs(ips[n]-ips[n-2]));    
	for(int i=n-3;i>0;i--){
		dp[i] = min(abs(ips[i+1]-ips[i])+dp[i+1],abs(ips[i+2]-ips[i])+dp[i+2]);
	}
	cout << dp[1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
