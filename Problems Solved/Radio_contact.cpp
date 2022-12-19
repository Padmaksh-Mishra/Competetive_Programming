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
	ll n,m; cin >> n >> m;
	vector<vll> dp(n+10,vll(m+10,INF));
	ll fx,fy,bx,by; cin >> fx >> fy >> bx >> by;
	string j,b; cin >> j >> b;
	int a=0,c=0;
	auto distance = [&](ll p,ll q)->ll{
		//ll sfx=fx,sfy=fy,sbx=bx,sby=by;
		for(;a<p+1;++a){
			if(j[a]=='N') fy++;
			else if(j[a]=='S') fy--;
			else if(j[a]=='E') fx++;
			else fx--;
		}
		for(;c<q+1;++c){
			if(b[c]=='N') by++;
			else if(b[c]=='S') by--;
			else if(b[c]=='E') bx++;
			else bx--;
		}
		return ((fx-bx)*(fx-bx) + (fy-by)*(fy-by));
	};
	dp[0][0] = 0;// exclude the first step;
	for(int p=0;p<n+1;++p){
		for(int q=0;q<m+1;++q){
			if(p>0&&q<m) dp[p][q] = min(dp[p][q],dp[p-1][q] + distance(p-1,q));
			if(p>0&&q>0) dp[p][q] = min(dp[p][q],dp[p-1][q-1] + distance(p-1,q-1));
			if(q>0&&p<n) dp[p][q] = min(dp[p][q],dp[p][q-1] + distance(p,q-1));
		}
	}
	cout << dp[n][m] << endl;
}
