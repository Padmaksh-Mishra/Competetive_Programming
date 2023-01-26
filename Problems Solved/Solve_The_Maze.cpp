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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,m; cin >> n >> m;
	vector<string> mat(n);
	for(int i=0;i<n;++i){
		cin >> mat[i];
	}	    
	auto ok = [&](ll x,ll y)->bool{
		if(x>-1&&x<n&&y>-1&&y<m){
			return true;
		}else{
			return false;
		}
	};
	vector<pll> drxn = {
		{1,0},{-1,0},{0,1},{0,-1}
	};

	//packing the bad people
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mat[i][j]=='B'){
				for(auto move : drxn){
					ll nx = i+move.f;
					ll ny = j+move.s;
					if(ok(nx,ny)){
						if(mat[nx][ny]=='G'){
							cout << "NO" << endl;
							return;
						}else if(mat[nx][ny]=='.'){
							mat[nx][ny]='#';
						}
					}
				}
			}
		}
	}

	//flood filling the leftover to see if all Good are visited
	vector<vll> vis(n,vll(m,0));
	function<void(ll,ll)> floodfill = [&](ll x,ll y)->void{
		
		if(!ok(x,y)) return;
		if(vis[x][y]||mat[x][y]=='#') return;
		vis[x][y] = 1;
		for(auto move : drxn){
			ll nx = x+move.f;
			ll ny = y+move.s;
			floodfill(nx,ny);	
		}	
	};

	floodfill(n-1,m-1);
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mat[i][j]=='G'&&!vis[i][j]){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}
