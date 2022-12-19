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

struct moocast{
	int x;
	int y;
	int p;
};

const int MOD = 1e9 +7;
const int N = 1e5 + 1;
vector<moocast> cows;
vi graph[201];
vector<bool> visited(201);
int visited_cows;

void setIO(string name = "sublime");

void dfs(int node){
	if(visited[node]) return;
	visited_cows++;
	visited[node] = true;
	// deb(node);
	for(auto child : graph[node]){
		dfs(child);
	}
}
void reset(){
	for(int i=0;i<201;++i) visited[i] = false;
}
void solve(){
	int n; cin >> n;
	int ans = 1;

	for(int i=0;i<n;++i){
		moocast cow;
		cin >> cow.x >> cow.y >> cow.p;
		cows.pb(cow);
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			// if(i==j) continue;
			int disx = cows[i].x-cows[j].x;
			int disy = cows[i].y-cows[j].y;
			// disy*=disy;
			// disx*=disx;
			int powr = cows[i].p;
			// powr*=powr;
			if((powr*powr)>= (disy*disy)+(disx*disx)) graph[i].pb(j);
		}
	}
	for(int i=0;i<n;++i){
		visited_cows=0;
		// fill(all(visited),false);
		reset();
		dfs(i);
		ans=max(ans,visited_cows);
		// cout << "-----------------------" << endl;
	}
	cout << ans << endl;
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