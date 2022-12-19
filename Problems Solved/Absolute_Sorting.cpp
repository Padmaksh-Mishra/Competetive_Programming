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
	ll n; cin >> n;
	vll v(n);
	for(int i=0;i<n;++i) cin >> v[i];

	auto ok = [v,n](ll k)->bool{
		ll pc = -1;
		vll t(n);

		for(int i=0;i<n;++i){
			t[i] = v[i];
			if(abs(t[i]-k)<pc) return false;
			t[i] = abs(t[i]-k);
			pc = t[i];
		}
		return true;
	};
	if(ok(0)) cout << 0 << endl;
	else if(ok(1000000000)) cout << 1000000000 << endl;
	else if(ok((v[0]+v[1]+1)/2)) cout << (v[0]+v[1]+1)/2 << endl;
	else cout << -1 << endl;
}
