//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int dp[100000];
void solve(){
	int n; cin >> n;
    int k; cin>> k;
	int h[n+1];
	for(int i=1;i<n+1;i++) cin >> h[i];

    for(int i=n-1;i>0;i--){
        int mini = MOD;
        for(int j=1;j<=k;j++){
            if(i+j>n) break;
            mini = min(dp[i+j] + abs(h[i+j]-h[i]),mini);
        }
        dp[i] = mini;
        //deb(dp[i]);
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
