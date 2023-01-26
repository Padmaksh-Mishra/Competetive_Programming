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
vector<vll> grid(1001,vll(1001)),vis(1001,vll(1001));
vll w = {8,4,2,1};
ll room,n,m;
void floodfill(ll x,ll y){
	// cout << x << " " << y << endl;
	if(x<0||y<0||x>n-1||y>m-1) return;
	if(vis[x][y]) return;
	else vis[x][y] = 1;
	room++;
	for(int i=0;i<4;++i){
		ll tmp = grid[x][y];
		// deb(tmp);
		if(!(tmp&w[i])){
			ll nx = x + (i==2) - (i==0);
			ll ny = y - (i==3) + (i==1);
			// cout << nx << " " << ny << endl;
			floodfill(nx,ny);
		}
	}
}
void solve(){
	cin >> n >> m;
	vll rooms;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> grid[i][j];
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			room = 0;
			if(!vis[i][j]){
				floodfill(i,j);
				rooms.emplace_back(room);
			}
		}
	}
	sort(all(rooms),greater<ll>());
	for(auto room : rooms){
		cout << room << " ";
	}
	cout << endl;
}
