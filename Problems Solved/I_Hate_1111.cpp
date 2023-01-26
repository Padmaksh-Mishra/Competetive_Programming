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
	while(n%10==0) n/=10;
	ll prv = (n%10);
	vll ans;
	while(n){
		n/=10;
		ll now = (n%10);
		deb(n);
		if(now==0) continue;
		ans.emplace_back(prv-now);
		prv = now;
	}	    
	// for(int i=0;i<siz(ans);++i){
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;
	if(ans[0]){
		cout << "NO" << endl;
	}else{
		for(int i=1;i<siz(ans);++i){
			if(ans[i]<0){
				cout << "NO" << endl;
				return;
			}
		}
		cout << "YES" << endl;
	}
}
