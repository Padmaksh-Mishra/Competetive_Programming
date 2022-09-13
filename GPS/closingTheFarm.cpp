# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;
const int N = 3001;
vi graph[N];
vi visited(N);
vi closed(N);
int vis;
void setIO(string name = "sublime");

void dfs(int v){
	if(visited[v]||closed[v]) return;
	visited[v] = 1;
	vis++;
	for(auto child : graph[v]){
		dfs(child);
	}
}
void solve(){
	int n,m; cin >> n >> m;
	for(int i=0;i<m;++i){
		int x,y; cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	dfs(1);
	if(vis!=n) NO;
	else YES;
	vi tbc(n);
	for(int i=0;i<n;++i) cin >> tbc[i];
	fill(visited.begin(), visited.end(),0);
	for(int i=0;i<n;++i){
		vis=0;
		closed[tbc[i]]=1;
		dfs(tbc[n-1]);
		if(vis!=n-i-1) NO;
		else YES;
		fill(visited.begin(), visited.end(),0);
	}
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
    int TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}
//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 