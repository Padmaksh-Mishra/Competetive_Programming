# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;

void solve(){
	int n; cin >> n;
	vector<string> v(n);
	ll ans = 0;
	map<string,ll> m;
	for(int i=0;i<n;++i) {
		cin >> v[i];
		m[v[i]]++;
	}
	// for(int i=0;i<n;++i){
	// 	for(int j=i+1;j<n;++j){
	// 		if(v[i]!=v[j]){
	// 			if((v[i][0]==v[j][0])||(v[i][1]==v[j][1])) ans++;
	// 		}
	// 	}
	// }
	// cout << ans << endl;
	for(auto ait = m.begin();ait!=m.end();++ait){
		pair<string,ll> a = (*ait);
		for(auto bit = m.begin();bit!=m.end();++bit){
			pair<string,ll> b = (*bit);
			// deb(a.f);
			// deb(b.f);
			if(a.f!=b.f){
				if(a.f[0]==b.f[0]||a.f[1]==b.f[1]) ans+=(a.s*b.s);
			}
		}
	}
	cout << ans/2 << endl;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 