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
bool lit[101][101],visited[101][101];
map<pair<ll,ll>,vector<pair<ll,ll>>> switches;
ll ans,n,m;
bool isValid(ll x,ll y){
	return (x>0&&y>0&&x<=n&&y<=n);
}
vector<pair<ll,ll>> moves = {
	{0,1},{0,-1},
	{1,0},{-1,0}
};
void turnOn(ll x,ll y);
void floodfill(ll x,ll y);

void solve(){
	cin >> n >> m;
	lit[1][1] = true;
	while(m--){
		ll a,b,c,d; cin >> a >> b >> c >> d;
		switches[make_pair(a,b)].pb(make_pair(c,d));
	}	
	floodfill(1,1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(lit[i][j]) ans++;
		}
	}
	cout << ans << endl;    
}
void turnOn(ll x,ll y){
	for(auto switchOn : switches[{x,y}]){ 
		lit[switchOn.f][switchOn.s] = true;
		bool ok = false;
		for(auto move : moves){
			ll cx = x+move.f,cy = y+move.s;
			if(isValid(cx,cy)&&visited[cx][cy]){
				ok = true;
			}
			if(ok) floodfill(x,y);
		}
	}
}
void floodfill(ll x,ll y){
	if(visited[x][y]||!lit[x][y]||!isValid(x,y)) return;
	else visited[x][y] = true;
	
	for(auto switchOn : switches[{x,y}]){ 
		lit[switchOn.f][switchOn.s] = true;
		for(auto move : moves){
			ll nx = switchOn.f+move.f,ny = switchOn.s+move.s;
			if(visited[nx][ny]){
				floodfill(switchOn.f,switchOn.s);
			}
		}
	}

	for(auto move : moves){
		ll cx = x+move.f,cy = y+move.s;
		if(isValid(cx,cy)){
			if(lit[cx][cy]){
				floodfill(cx,cy);
			}
		}
	}
}
