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
ll matrix[501][501];
bool visited[501][501],waypoints[501][501];
vector<pair<ll,ll>> moves = {
	{1,0},{-1,0},
	{0,1},{0,-1}
};
ll m,n,maxh;
void reset(){
	for(int i=0;i<501;++i){
		for(int j=0;j<501;++j){
			visited[i][j]=0;
		}
	}
}
bool isValid(ll x,ll y){
	if(x<0||x>=m||y<0||y>=n) return false;
	else return true;
}
void floodfill(ll x,ll y){
	if(!isValid(x,y)||visited[x][y]) return;
	else visited[x][y]=true;
	
	for(auto move : moves){
		ll xc = x+move.f;
		ll yc = y+move.s;
		if(abs(matrix[x][y]-matrix[xc][yc])<= maxh) floodfill(xc,yc);
	}
}

bool reachable(ll x,ll y,ll h){
	maxh = h;
	reset();
	floodfill(x,y);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(!visited[i][j]&&waypoints[i][j]) return false;
		}
	}
	return true;
}
void solve(){
	cin >> m >> n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> matrix[i][j];
		}
	}
	ll x,y;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> waypoints[i][j];
			if(waypoints[i][j]) x=i,y=j;
		}
	}
	ll lo = 0,hi = 1e9;
	ll mid;
	while(hi-lo>1){
		mid=(lo+hi)>>1;
		if(reachable(x,y,mid)){
			hi = mid;
		}else lo = mid+1;
	}
	if(reachable(x,y,lo)) cout << lo << endl;
	else if(reachable(x,y,mid)) cout << mid << endl;
	else cout << hi << endl;
}
