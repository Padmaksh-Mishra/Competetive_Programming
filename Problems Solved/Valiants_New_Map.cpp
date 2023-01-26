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
	
	vector<vll> mp(n+1,vll(m+1));
	for(int i=1;i<n+1;++i){
		for(int j=1;j<m+1;++j){
			cin >> mp[i][j];
		}
	}
	auto ok = [&](ll l)->bool{
		vector<vll> ps(n+1,vll(m+1,0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				ps[i][j] = (mp[i][j]>=l)
							+ ps[i - 1][j]
							+ ps[i][j - 1]
							- ps[i - 1][j - 1];
			}
		}
		for(int i=l;i<=n;++i){
			for(int j=l;j<=m;++j){
				//cout << i << " " << j << endl;
				ll init = (ps[i][j] - ps[i-l][j] - ps[i][j-l] + ps[i-l][j-l]);
				// cout << l << " " << init << endl;
				if(init==l*l) return true;
			}
		}
		return false;
	};
	ll s=1,e=min(n,m);
	ll mid;
	// deb(e);
	while(e-s>1){
		mid = s + ((e-s)>>1);
		if(ok(mid)){
			s = mid;
		}else{
			e = mid-1;
		}
	}
	if(ok(e)) cout << e << endl;
	else if(ok(s)) cout << s << endl;
	else cout << 0 << endl;	    
}
