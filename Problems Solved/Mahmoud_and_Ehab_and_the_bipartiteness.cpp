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
vll graph[100001];
bool visited[100001],color[100001],bad;
ll colorone;
void dfs(ll v,bool c=0){
	if(visited[v]) return;
	else visited[v] = true;
	color[v] = c;
	if(c==1) colorone++;
	for(ll node : graph[v]){
		if(visited[node]) {
			if(color[node]==c) {
				bad = 1;
			}
		}
		else dfs(node,!c);
	}
}
void solve(){
	int n; cin >> n;
	int m = n-1;
	while(m--){
		ll a,b; cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for(int i=1;i<=n;++i){
		if(!visited[i]) dfs(i,0);
	}
	if(bad){
		cout << 0 << endl;
	}else{
		cout << ((n-colorone)*colorone) - n + 1 << endl;
	}
}
