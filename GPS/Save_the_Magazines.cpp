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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	string s; cin >> s;
	vll mags(n+1,0);
	for(int i=0;i<n;++i){
		cin >> mags[i];
	}
	s+='0';    
	ll ans = 0;
	ll dp[n+1][2];
	for(int i=0;i<=n;++i){
		dp[i][1]=dp[i][0]=0;
	}
	for(int i=1;i<=n;++i){
		if(s[i-1]=='1'){
			dp[i][0] = max(dp[i][0],dp[i-1][0]+mags[i-1]);
			dp[i][0] = max(dp[i][0],dp[i-1][1]);
			if(s[i]=='1') dp[i][1] = max(dp[i][1],dp[i-1][1]+mags[i-1]);
		}else{
			if(s[i]=='1') dp[i][1] = max(dp[i][1],dp[i-1][0]+mags[i-1]);
			dp[i][0] = max(dp[i][0],dp[i-1][0]);
		}
	}
	cout << max(dp[n][1],dp[n][0]) << endl;
}
