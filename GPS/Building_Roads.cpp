# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
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

using namespace std;
const ll MOD = 1e9 +7;
void setIO(string name = "sublime");

vi graph[100001];
vi visited(100001);

void dfs(int node){
	if(visited[node]) return;
	visited[node] = 1;
	for(auto child : graph[node]){
		dfs(child);
	}
}

void solve(){
	int n,m; cin >> n >> m;
	int x,y; 
	while(m--){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	int ops = 0;
	vi dest;
	dfs(1);
	for(int i=1;i<=n;++i){
		if(visited[i]==0){
			ops++;
			dest.pb(i);
			dfs(i);
		}
	}
	cout << ops << endl;
	for(auto val : dest) cout << 1 << " " << val << endl;
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