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
const int N = 2e5 + 1;

void setIO(string name = "sublime");
vector<bool> visited(N);
vi graph[N];

void dfs(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(auto child : graph[node]){
		dfs(child);
	}
}

void solve(){
	int n; cin >> n;
	string s; cin >> s;
	vi hsh(2*n + 1);
	hsh[0] = 0;
	for(int i=1;i<=2*n;++i){
		hsh[i] = hsh[i-1] + ((s[i-1]=='(') ? 1 : -1);
		deb(hsh[i]);
	}	
	int cnt = 0;
	for(int i=1;i<2*n;++i){
		for(int j=i+1;j<=2*n;++j){
			if((hsh[i]-hsh[j]==1)&&(s[i-1]=='(')&&(s[j-1]==')')){
				cout << i << " " << j << endl;
				graph[i].pb(j);
				graph[j].pb(i);
			}
		}
	}
	vi graph[2*n];
	for(int i=1;i<=2*n;++i){
		if(visited[i]) continue;
		// fill(all(visited),false);
		cnt++;
		dfs(i);
	}
	cout << cnt << endl;
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
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