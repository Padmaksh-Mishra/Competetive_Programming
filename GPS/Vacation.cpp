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
	vector<int> dp(3,0);
	for(int day = 0;day<n;day++){
		vector<int> ndp(3,0);
		vector<int> cost(3);
		for(int i = 0;i<3;i++){
			cin >> cost[i];
		}

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=j){
					ndp[j] = max(ndp[j],dp[i]+cost[j]);
				}
			}
		}
		dp = ndp;
	}    
	cout << max(max(dp[0],dp[1]),dp[2]);
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
