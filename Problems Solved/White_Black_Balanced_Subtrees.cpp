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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
vector<ll> graph[4001];
vector<bool> color(4001);
vector<ll> balance(4001);
vector<bool> visited(4001);
ll answer;
void reset(){
	for(int i=0;i<4001;++i){
		graph[i].clear();
		color[i]=balance[i]=visited[i]=answer=0;
	}
}
void dfs(ll parent){
	if(visited[parent]) return;
	else visited[parent] = true;
	//deb(parent);
	for(auto child : graph[parent]){
		//deb(child);
		dfs(child);
		balance[parent]+=balance[child];
		//deb(balance[child]);
	}
	ll add = ((color[parent]) ? 1:-1);
	balance[parent]+= add;
	//deb(balance[parent]);
	if(balance[parent]==0) answer++;
}

void solve(){
	reset();
	ll n; cin >> n;
	ll tmp;
	for(int i=2;i<=n;++i){
		cin >> tmp;
		//graph[i].pb(tmp);
		graph[tmp].pb(i);
	}
	for(int i=1;i<=n;++i) {
		char tmp; cin >> tmp;
		color[i] = (tmp=='W');
	}
	dfs(1);    
	cout << answer << endl;
}
