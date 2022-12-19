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
const int N = 1e5;
vector<pair<int,int>> graph[N+1];
vi level(N+1,MOD);

int bfs(int n){
	deque<int> q;
	q.pb(1);
	level[1]=0;
	while(!q.empty()){
		int curr_v = q.front();
		q.pop_front();
		for(auto &child : graph[curr_v]){
			int child_v = child.f;
			int w = child.s;
			if(level[curr_v]+w<level[child_v]){
				level[child_v] = level[curr_v] + w;
				if(w==1) q.push_back(child_v);
				else q.push_front(child_v);
			}
		}
	}
	return (level[n]==MOD) ? -1 : level[n];
}
void solve(){
	int n,m; cin >> n >> m;
	for(int i=0;i<m;++i){
		int v,e; cin >> v >> e;
		if(v==e) continue;
		graph[v].pb({e,0});
		graph[e].pb({v,1});
	}
	cout << bfs(n) << endl;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 