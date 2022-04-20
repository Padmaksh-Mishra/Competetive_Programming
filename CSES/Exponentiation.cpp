# include <iostream>
# define endl "\n";
using namespace std;

const int MOD = 1e9 + 7;

void solve();
long long binExpo(int b,int p);

int main(){
	int tc; cin >> tc;
	while(tc--) solve();
	return 0;
}

void solve(){
	int a,b; cin >> a >> b;
	cout << binExpo(a,b) << endl;
	return;
}

long long binExpo(int b, int p){
	long long ans = 1,tmp = b;
	while(p){
		if(p&1) ans = (ans*1LL*tmp)%MOD;
		tmp = (tmp*tmp*1LL)%MOD;
		p = p>>1;
	}
	return ans;
}