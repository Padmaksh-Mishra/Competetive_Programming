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
	ll n,max_depth;
	cin >> n;
	vll sovs(n);
	vector<string> path(n);

	for(int i=0;i<n;++i){
		cin >> sovs[i];
	}	    
	vector<vll> dp(n,vll(n,INF)),value(n,vll(n,0));

	for(int i=0;i<n;++i){
		cin >> path[i];
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(path[i][j]=='Y') dp[i][j] = 1,value[i][j] = sovs[j];
		}
	}
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				ll new_depth = dp[i][k]+dp[k][j];
				if(new_depth<dp[i][j]){
					dp[i][j]=new_depth;
					value[i][j]=value[i][k]+value[k][j];
				}
				else if((new_depth==dp[i][j])&&((value[i][k]+value[k][j])>value[i][j])){
					value[i][j]=value[i][k]+value[k][j];
				}
			}
		}
	}
	ll q; cin >> q;
	while(q--){
		ll a,b; cin >> a >> b;
		a--;
		b--;
		max_depth = dp[a][b];
		if(max_depth==INF){
			cout << "Impossible" << endl;
		}else{
			cout << max_depth << " " << value[a][b] + sovs[a] << endl;
		}
	}
}
