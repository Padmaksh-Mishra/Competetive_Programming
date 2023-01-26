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
	ll n,m; cin >> n >> m;
	vector<vll> graph(n+1);
	vector<vll> dp((1<<n),vll(n+1));
	while(m--){
		ll a,b; cin >> a >> b;
		graph[b].emplace_back(a);
	}
	dp[1][1] = 1;
	for(int k=2;k<(1<<n);++k){
		if((k&(1<<(n-1)))&&(k!=((1<<n)-1))) continue;
		for(int c=1;c<n+1;++c){
			if(!(k&(1<<(c-1)))) continue;	//if the city is not even in the subset then wtf are you counting
			for(auto val : graph[c]){
				if(k&(1<<(val-1))){		//if this prv node is in the subset then only we can reach this subset state k
											//as both the source bit and the destination bit should be set
					(dp[k][c] += dp[k^(1<<(c-1))][val])%=MOD;
				}
			}
		}
	}
	cout << dp[(1<<n)-1][n] << endl;
}
