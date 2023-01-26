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

void solve(){
	ll n; cin >> n;
	vector<vll> grid(n,vll(n,0));
	for(int i=0;i<n;++i){
		ll val; cin >> val;
		ll cnt = val;
		ll r = i,c = i;
		while(cnt>0&&r<n){
			while(grid[r][c]==0&&c>=0){
				grid[r][c] = val;
				c--;
				cnt--;
			}
			c++;
			r++;
		}
	}	    
	for(int i=0;i<n;++i){
		for(int j=0;j<i+1;++j){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}
