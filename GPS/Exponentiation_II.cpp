# include <iostream>
# define endl "\n";
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

void solve();
long long binExpo(ll b,ll p);
ll binExpoPow(ll b,ll p);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc; cin >> tc;
	while(tc--) solve();
	return 0;
}

void solve(){
	int a,b,c; cin >> a >> b >> c;
	cout << binExpo(a,binExpoPow(b,c)) << endl;
	return;
}

ll binExpo(ll b, ll p){
	ll ans = 1,tmp = b;
	while(p){
		if(p&1) ans = (ans*1LL*tmp)%MOD;
		tmp = (tmp*tmp*1LL)%MOD;
		p = p>>1;
	}
	return ans;
}

ll binExpoPow(ll b, ll p){
	ll ans = 1,tmp = b;
	while(p){
		if(p&1) ans = (ans*1LL*tmp)%(MOD-1); // since for modluing the pow we use pow % etf(mod)
		tmp = (tmp*tmp*1LL)%(MOD-1);		// since m is prime here etf is m-1
		p = p>>1;
	}
	return ans;
}