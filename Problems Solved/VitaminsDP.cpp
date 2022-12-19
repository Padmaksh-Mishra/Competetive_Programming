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

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

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
const ll INF = 1e17+9;
void solve(){
	ll n; cin >> n;
	ll dp[n+1][8];    
	for(int i=0;i<n+1;++i){
		for(int j=0;j<8;++j){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	char vitamins[3] = {'A','B','C'};
	for(int i=0;i<n;++i){
		ll cost; cin >> cost;
		string s; cin >> s;
		ll string_mask = 0;
		for(int v=0;v<3;++v){
			for(int k=0;k<siz(s);++k){
				if(vitamins[v]==s[k]){
					string_mask|=(1<<v);
				}
			}
		}
		for(int mask=0;mask<8;++mask){
			dp[i+1][mask] = min(dp[i][mask],dp[i+1][mask]);
			dp[i+1][mask|string_mask] = min(dp[i][mask] + cost,dp[i+1][mask|string_mask]);
		}
	}
	if(dp[n][7]==INF) cout << -1 << endl;
	else cout << dp[n][7] << endl;
}
