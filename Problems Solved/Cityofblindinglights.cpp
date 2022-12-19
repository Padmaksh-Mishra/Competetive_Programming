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
ll dist[401][401];
vector<bool> visited(401);

void solve(){
	for(int i=0;i<401;++i){
		for(int j=0;j<401;++j){
			dist[i][j] = MOD;
			if(i==j) dist[i][j]=0;
		}
	}
	ll n,m; cin >> n >> m;
	for(int i=0;i<m;++i){
		int a,b,w; cin >> a >> b >> w;
		dist[a][b] = w;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	ll q; cin >> q;
	while(q--){
		ll a,b; cin >> a >> b;
		cout << ((dist[a][b]==MOD) ? -1 : dist[a][b]) << endl;
	}
}
