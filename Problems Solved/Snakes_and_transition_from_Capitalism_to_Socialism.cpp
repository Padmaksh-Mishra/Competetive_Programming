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

const ll MOD = 1e15 +7;
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
ll graph[501][501];
ll visited[501][501];
ll level[501][501];
vector<pair<ll,ll>> movements = {
	{1,0},{0,1},{-1,0},{0,-1},
	{1,1},{-1,1},{-1,-1},{1,-1}
};
ll n,m;

bool isValid(ll x,ll y){
	return (x>0&&y>0&&x<=n&&y<=m);
}
ll bfs(){
	ll maxi = 0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			maxi = max(maxi,graph[i][j]);
		}
	}
	queue<pair<ll,ll>> q;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(maxi==graph[i][j]) {
				visited[i][j]=1;
				q.push(make_pair(i,j));
				level[i][j]=0;
			}
		}
	}
	ll ans = 0;
	while(!q.empty()){
		auto parent = q.front();
		ll px = parent.f;
		ll py = parent.s;
		q.pop();
		for(auto move : movements){
			ll cx = px+move.f;
			ll cy = py + move.s;
			if(!isValid(cx,cy)) continue;
			if(visited[cx][cy]) continue;
			visited[cx][cy] = 1;
			q.push(make_pair(cx,cy));
			level[cx][cy] = level[px][py] + 1;
			ans = max(ans,level[cx][cy]);
		}
	}
	return ans;
}
void reset(){
	for(int i=1;i<=500;++i){
		for(int j=1;j<=500;++j){
			visited[i][j]=0;
			level[i][j] = MOD;
		}
	}
}
void solve(){
	reset();
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin >> graph[i][j];
		}
	} 
	cout << bfs() << endl;  
}
