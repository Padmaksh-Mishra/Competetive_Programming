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
ll dp[1001][1001];
void solve(){
	string s,t; cin >> s >> t;
	ll x = s.size();
	ll y = t.size();
	
	for(int i=0;i<=x;++i){
		for(int j=0;j<=y;++j){
			if(s[i]==t[j]){
				dp[i][j] = max(dp[i-1][j-1]+1,dp[i][j]);
			}else {
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	cout << dp[x][y] << endl;
}
