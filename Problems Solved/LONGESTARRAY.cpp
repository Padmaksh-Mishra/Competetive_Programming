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
    setIO("sublime");    //Does not work with Google     
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
	vll v(n);
	ll ord = 0;
	for(int i=0;i<n;++i) {
		cin >> v[i];
		ord|=v[i];
	}
	vector<vll> ps(n+1,vll(32,0));

	for(ll i=0;i<n;++i){
		// deb(v[i]);
		for(ll j=0;j<31;++j){
			ps[i+1][j] = ps[i][j]+(((v[i]>>j)&1ll)==1);
			//cout << ps[i+1][j] << " ";
		}
		//cout << endl;
	}
	auto orfinder = [&ps](ll i,ll j)->ll{
		ll curor = 0;
		// cout << i << ' ' << j << endl;
		for(int b=0;b<32;++b){
			if(ps[j][b]-ps[i][b]>0){
				curor|=(1ll<<b);
			}
		}
		return curor;
	};
	auto orrem = [&ps,n](ll i,ll j)->ll{
		ll curor = 0;
		//cout << i << ' ' << j << endl;
		for(int b=0;b<32;++b){
			if(ps[n][b]-(ps[j][b]-ps[i][b])>0){
				curor|=(1ll<<b);
			}
		}
		return curor;
	};
	ll j=1;
	ll ans = 0;
	for(int i=0;i<n&&j<=n;++i){
		ll curor = orfinder(i,j);
		while(curor<=ord&&j<n){
			// deb(curor);
			ll orm = orrem(i,j);
			if((j-i<n)&&orm==curor) ans = max(ans,j-i);
			++j; 
			curor = orfinder(i,j);
		}
		ll orm = orrem(i,j);
		if((j-i<n)&&orm==curor) ans = max(ans,j-i);
		if(j>0) --j;
	}
	if(ans==0) ans = -1;
	cout << ans << endl;
}
