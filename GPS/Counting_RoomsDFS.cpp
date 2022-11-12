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
bool graph[1001][1001],visited[1001][1001];
ll connected_components;
ll n,m; 
void dfs(ll i,ll j){
	if(i<1||i>n||j<1||j>m) return;
	if(!graph[i][j]) return;
	if(visited[i][j]) return;
	visited[i][j] = 1;

	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j-1);
	dfs(i,j+1);
}

void solve(){
	cin >> n >> m;
	for(ll r=1;r<=n;++r){
		for(ll c=1;c<=m;++c){
			char tmp; cin >> tmp;
			graph[r][c] = (tmp=='#') ? 0 : 1;
		}
	}
	for(ll r=1;r<=n;++r){
		for(ll c=1;c<=m;++c){
			if(!visited[r][c]&&graph[r][c]){
				dfs(r,c);
				connected_components++;
			}
		}
	}
	cout << connected_components << endl;
}
