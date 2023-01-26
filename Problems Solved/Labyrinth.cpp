# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
ll n,m; 
vector<string> graph(1001);
vector<pll> moves = {
	{-1,0},{1,0},
	{0,1},{0,-1}
};

bool is_ok(ll x,ll y){
	return (x>-1&&x<n&&y>-1&&y<m&&graph[x][y]!='#');
}

void solve(){
	cin >> n >> m;
	pll a,b;
	for(int i=0;i<n;++i){
		cin >> graph[i];
		for(int j=0;j<m;++j){
			if(graph[i][j]=='A'){
				a = {i,j};
			}
			if(graph[i][j]=='B'){
				b = {i,j};
			}
		}
	}	    
	queue<pll> q;
	q.push(a);
	pll parent[n][m];
	vector<vll> distance(n,vll(m)),vis(n,vll(m));
	while(!q.empty()){
		ll x = q.front().f;
		ll y = q.front().s;
		q.pop();
		for(pll drxn : moves){
			ll nx = x + drxn.f;
			ll ny = y + drxn.s;
			if(!is_ok(nx,ny)||vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push(make_pair(nx,ny));
			parent[nx][ny] = make_pair(x,y);
			distance[nx][ny] = distance[x][y] + 1;
		}	
	}
	ll x = b.f,y=b.s;
	if(distance[x][y]){
		cout << "YES" << endl;
		cout << distance[x][y] << endl;
		vector<char> ans;
		while(make_pair(x,y)!=a){
			pll tmp = parent[x][y];
			if(tmp.f==x){
				if(tmp.s>y) ans.emplace_back('L');
				else ans.emplace_back('R');
			}else{
				if(tmp.f>x) ans.emplace_back('U');
				else ans.emplace_back('D');
			}
			x = tmp.f;
			y = tmp.s;
		}
		reverse(all(ans));
		for(char c : ans){
			cout << c;
		}
		cout << endl;
	}else {
		cout << "NO" << endl;
	}
}
