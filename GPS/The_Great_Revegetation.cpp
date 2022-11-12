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
vector<pair<int,bool>> graph[100001];
vector<int> color(100001,-1);
int connected_Components;
vector<bool> visited(100001);
bool bad;
void dfs(int parent,int c=0){
	if(bad) return;
	if(visited[parent]) return;
	else visited[parent] = true;
	color[parent] = c;
	for(auto child : graph[parent]){
		if(color[child.f]==color[parent]&&child.s==1){
			bad = true;
			return;
		}
		if(child.s==1) dfs(child.f,!c);
		else dfs(child.f,c);
	}
}

void solve(){
	int n,m; cin >> n >> m;
	while(m--){
		char t; cin >> t;
		int a,b; cin >> a >> b;
		bool zo = (t=='S') ? 0:1;
		graph[a].pb({b,zo});
		graph[b].pb({a,zo});
	} 
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			dfs(i);
			connected_Components++;
		}
	}
	if(bad) cout << 0 << endl;
	else{
		cout << 1;
		for(int i=1;i<=connected_Components;++i) cout << 0;
		cout << endl;
	}
}
