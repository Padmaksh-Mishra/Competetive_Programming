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
    ll n,w; cin >> n >> w;
    vector<vll> dp(n+1,vll(100001,INF));
    dp[0][100000] = INF;
    vector<pll> v;
    for(int i=0;i<n;++i){
    	ll w,val; cin >> w >> val;
    	v.emplace_back(make_pair(w,val));
    }
    for(int i=0;i<n+1;++i){
    	for(int j=100000;j>-1;--j){
    		if(i==0&&j==0){
    			dp[i][j]=0;
    		}
    		if(i<n) dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
    		if(i<n&&j<1000001-v[i].s+1) dp[i+1][j+v[i].s] = min(dp[i+1][j+v[i].s],dp[i][j]+v[i].f);	
    	}
    }
    for(int j=100001;j>0;--j){
    	if(dp[n][j]<w+1){
    		cout << dp[n][j] << endl;
    		return;
    	}
    }
}
