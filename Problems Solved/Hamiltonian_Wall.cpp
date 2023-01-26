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
ll m;
vector<string> v(2);
vector<vll> vis(2,vll(N));

bool ok(ll x,ll y){
	return ((x>-1&&x<2)&&(y>-1&&y<m));
}
void ffs(ll x,ll y){

	vis[x][y] = 1;
	if(ok(x-1,y)&&vis[x-1][y]==0&&v[x-1][y]=='B'){
		ffs(x-1,y);
	}else if(ok(x+1,y)&&vis[x+1][y]==0&&v[x+1][y]=='B'){
		ffs(x+1,y);
	}else if(ok(x,y+1)&&vis[x][y+1]==0&&v[x][y+1]=='B'){
		ffs(x,y+1);
	}
}
void solve(){
	cin >> m;
	cin >> v[0];
	cin >> v[1];
	auto reset = [&]()->void{
		for(int i=0;i<m;++i){
			vis[0][i]=vis[1][i]=0;
		}
	};
	auto check = [&]()->bool{
		for(int i=0;i<m;++i){
			if(v[0][i]=='B'&& vis[0][i]==0){
				return false;
			}
			if(v[1][i]=='B'&& vis[1][i]==0){
				return false;
			}
		}	
		return true;
	};
	reset();
	if(v[0][0]=='B'){
		ffs(0,0);
		if(check()){
			cout << "YES" << endl;
			return;
		}
	}
	reset();
	if(v[1][0]=='B'){
		ffs(1,0);
		if(check()){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}
