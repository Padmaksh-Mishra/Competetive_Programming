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
    setIO("lightson");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
queue<pll> master;
vector<vll> grid(101,vll(101)),vis(101,vll(101)),on(101,vll(101));
vector<pll> switches[101][101];
ll n,m,ans;
vector<pll> moves = {
	{-1,0},{1,0},
	{0,1},{0,-1}
};

bool is_ok(ll x,ll y){
	return (x>-1&&x<n&&y>-1&&y<n&&on[x][y]);
}
void ff(ll x,ll y){
	if(!is_ok(x,y)) return;
	if(vis[x][y]) return;
	else vis[x][y] = 1;
	for(auto sin : switches[x][y]){
		if(!on[sin.f][sin.s]) ans++;
		on[sin.f][sin.s] = 1;
		for(pll drxn : moves){
			ll nx = sin.f + drxn.f;
			ll ny = sin.s + drxn.s;
			if(is_ok(nx,ny)&&vis[nx][ny]){
				master.push(sin);
			}
		}
	}
	for(pll drxn : moves){
		ll nx = x + drxn.f;
		ll ny = y + drxn.s;
		ff(nx,ny);
	}
}
void solve(){
	cin >> n >> m;
	while(m--){
		ll x,y,a,b; cin >> x >> y >> a >> b;
		--x,--y,--a,--b;
		switches[x][y].emplace_back(make_pair(a,b));
	} 
	on[0][0] = 1;
	master.push(make_pair(0,0));
	while(!master.empty()){
		pll go = master.front();
		// cout << go.f << " " << go.s << endl;
		ll x = go.f;
		ll y = go.s;
		master.pop();
		ff(x,y);
	}
	cout << ans+1 << endl;
}