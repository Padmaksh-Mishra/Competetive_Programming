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
ll matrix[501][501],dp[501][501];
bool visited[501][501],waypoints[501][501];
vector<pair<ll,ll>> pts;
vector<pair<ll,ll>> moves = {
	{1,0},{-1,0},
	{0,1},{0,-1}
};
ll m,n;
void setit(){
	for(int i=0;i<501;++i){
		for(int j=0;j<501;++j){
			dp[i][j] = MOD;
		}
	}
}
bool isValid(ll x,ll y){
	if(x<0||x>=m||y<0||y>=n) return false;
	else return true;
}
void floodfill(ll x,ll y){
	if(visited[x][y]) return;
	else visited[x][y]=true;
	
	for(auto move : moves){
		ll xc = x+move.f;
		ll yc = y+move.s;
		if(isValid(xc,yc)){
			if(xc==0&&yc==4){
				cout << x << " " << y << endl;
				deb(dp[x][y]);	
			}
			
			dp[xc][yc] = min(max(((dp[x][y]==MOD) ? -1 : dp[x][y]),abs(matrix[x][y]-matrix[xc][yc])),dp[xc][yc]);
			if(xc==0&&yc==4){
				cout << xc << " " << yc << endl;
				deb(dp[xc][yc]);	
			}

			floodfill(xc,yc);
		}
	}
}

void solve(){
	cin >> m >> n;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> matrix[i][j];
		}
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> waypoints[i][j];
			if(waypoints[i][j]) pts.pb(make_pair(i,j));
		}
	}
	setit();
	pair<ll,ll> start = pts[0];
	dp[start.f][start.s]=0;
	floodfill(start.f,start.s);
	ll ans = -1;
	for(auto val : pts){
		cout << val.f << " " << val.s << endl;
		deb(dp[val.f][val.s]);
		ans=max(ans,dp[val.f][val.s]);
	}
	cout << ans << endl;
}
