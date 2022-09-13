# include <bits/stdc++.h>
# define DEATH ios_base::sync_with_stdio(false); 
# define AWAITS cin.tie(NULL); 
# define YOU cout.tie(NULL);
# define int long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "No" << endl
# define YES cout << "Yes" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (int)(x).size()
# define vi vector<int>
# define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = 1e9 +7;
const int N = 1e5 + 1;
vi graph[N];
vi graphR[N];
vector<bool> visited(N);

void setIO(string name = "sublime");

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(auto child : graph[node]){
		dfs(child);
	}
}
void dfsR(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(auto child : graphR[node]){
		dfs(child);
	}
}
void solve(){
	int n,m; cin >> n >> m;
	for(int i=0;i<m;++i){
		int a,b;cin >> a >> b;
		graph[a].pb(b);
		graphR[b].pb(a);
	}
	//THE TLE CODE.........
	// for(int j=1;j<=n;++j){
	// 	fill(all(visited),false);
	// 	dfsR(j);
	// 	for(int i=1;i<=n;++i){
	// 		if(visited[i]==false){
	// 			cout << "NO" << endl;
	// 			cout << j << " " << i << endl;
	// 			return;
	// 		}
	// 	}
	// }
	// cout << "YES" << endl;

	fill(all(visited),false);
	dfs(1);
	for(int i=1;i<=n;++i){
		// deb(i);
		if(!visited[i]){
			cout << "NO" << endl;
			cout << 1 << " " << i << endl;
			return;
		}
	}
	fill(all(visited),false);
	dfsR(1);
	for(int i=1;i<=n;++i){
		deb(visited[i]);
		if(!visited[i]){
			cout << "NO" << endl;
			cout << i << " " << 1 << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
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
	if((int)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}