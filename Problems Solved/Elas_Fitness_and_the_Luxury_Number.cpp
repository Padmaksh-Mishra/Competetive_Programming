# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

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
	cin.tie(NULL); 
	cout.tie(NULL);
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
ll floorSqrt(ll x) {
  	ll left = 0, right = 1000000009;
  	while (right > left) {
      	ll mid = (left + right) / 2;
      	if (mid * mid > x) right = mid;
      	else left = mid + 1;
  	}
  	return left - 1;
}

void solve(){
	ll l,r; cin >> l >> r;
	ll sfl=0,sfr=0;
	ll ans = 0;
	ll sl = floorSqrt(l);
	ll sr = floorSqrt(r);
	if(sl==sr){
		ans = 0;
		for (int i = 0; i < 3; i++) {
		  	if (l <= sr * (sr + i) && sr * (sr + i) <= r) ans++;
	    }
	}else{
		ans = (sr-sl-1)*3;
		for (int i = 0; i < 3; i++) {
		  	if (l <= sl * (sl + i) && sl * (sl + i) <= r) ans++;
		  	if (l <= sr * (sr + i) && sr * (sr + i) <= r) ans++;
	    }
	}
	cout << ans << endl;
}
