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

const ll MOD = 998244353;
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
	ll n; cin >> n;
	ll h = (n>>1);
	vector<vector<vll>> dp(h+1,vector<vll> (h+1,vll(3,0)));
	dp[0][0][0] = 1;
	for(int a=0;a<h+1;++a){
		for(int b=0;b<h+1;++b){
			for(int c=0;c<3;++c){
				if(c==0){
					ll turn = (a+b)%4;
					ll chance;
					if(turn==1||turn==2) chance = 1;
					else if(turn==3||turn==0) chance = 2;
					if(a<h) dp[a+1][b][1*(chance!=1)]+=dp[a][b][0];
					if(b<h) dp[a][b+1][2*(chance!=2)]+=dp[a][b][0];
				}else{
					if(a<h) dp[a+1][b][c]+=dp[a][b][c];
					if(b<h) dp[a][b+1][c]+=dp[a][b][c];
				}
			}
		}
	}	    
	cout << dp[h][h][1]%MOD << " " << dp[h][h][2]%MOD << " " << dp[h][h][0] << endl;
}
