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
ll graph[501][501];
const ll INF = 1e14+7;
void reset(){
	for(int i=0;i<501;++i){
		for(int j=0;j<501;++j){
			graph[i][j] = INF;
		}
	}
}
void solve(){
	ll n; cin >> n;
	//reset();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin >> graph[i][j];
		}
	}  
	vll remove(n);
	vll ans;
	for(int i=0;i<n;++i) cin >> remove[i];
	reverse(all(remove));
	for(int k=0;k<n;++k){
		ll sum = 0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				graph[i][j] = min(graph[i][j],graph[i][remove[k]]+graph[remove[k]][j]);
			}
		}
		for(int i=0;i<=k;++i){
			for(int j=0;j<=k;++j){
				sum+=graph[remove[i]][remove[j]];
			}
		} 
		ans.pb(sum);	
	} 
	reverse(all(ans));
	for(auto val : ans){
		cout << val << ' ';
	} 
	cout << endl;
}
