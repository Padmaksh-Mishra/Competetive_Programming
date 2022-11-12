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
ll dp[1001][2001];

void solve(){
	ll n,k,p; cin >> n >> k >> p;
	vll people(n),keys(k);
	for(int i=0;i<n;++i) cin >> people[i];
	for(int i=0;i<k;++i) cin >> keys[i];    
	for(int i=0;i<=n;++i){
		for(int j=0;j<=k;++j){
			dp[i][j] = 1e17+9;
		}
	}	
	sort(all(people));
	sort(all(keys));
	dp[0][0] = 0;
	for(int i=0;i<k;++i){
		for(int j=0;j<=n;++j){
			dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
			if(j<n) dp[i+1][j+1] = min(dp[i+1][j+1],max(dp[i][j],abs(p-keys[i])+abs(keys[i]-people[j])));						
		}
	}
	cout << dp[k][n] << endl;
}
