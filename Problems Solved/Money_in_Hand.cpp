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
	ll n,x; cin >> n >> x;
	vll a(n),b(n);
	for(int i=0;i<n;++i){
		cin >> a[i] >> b[i];
	}	    
	vector<vll> dp(x+1,vll(n+1));
	dp[0][0] = 1;
	for(int i=0;i<n;++i){
		for(int sum = 0;sum<x+1;++sum){
			for(int j=0;j<b[i]+1;++j){
				ll add = (j*a[i]);
				if(sum+add<x+1) dp[sum+add][i+1] |= dp[sum][i];
			}
		}
	}
	if(dp[x][n]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
