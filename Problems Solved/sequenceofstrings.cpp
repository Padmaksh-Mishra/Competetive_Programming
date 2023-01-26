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
vll vis(101);
vector<vll> graph(101,vll(101));

void dfs(ll v){
	if(vis[v]) return;
	vis[v]=1;
	for(auto c:graph[v]){
		dfs(c);
	}
}
void solve(){
	ll n,m; cin >> n >> m;;
	while(m--){
		ll a,b; cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}
	ll ans = 0;
	for(int i=1;i<n+1;++i){
		if(!vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans << endl;
}

