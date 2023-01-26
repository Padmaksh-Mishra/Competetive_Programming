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
ll n,m;
vll graph[100001];
vll hight(100001);
vll vis(100001);
void dfs(ll p){
	if(vis[p]) return;
	else vis[p] = 1;
	for(auto c : graph[p]){
		dfs(c);
		hight[p] = max(hight[c]+1,hight[p]);
	}
}
void solve(){
	cin >> n >> m;
	for(int i=0;i<m;++i){
		ll a,b; cin >> a >> b;
		graph[a].emplace_back(b);
	}		    
	for(int i=1;i<n+1;++i){
		if(!vis[i]) dfs(i);
	}
	ll ans = -1;
	for(int i=1;i<n+1;++i){
		ans = max(ans,hight[i]);
	}
	cout << ans << endl;
}
