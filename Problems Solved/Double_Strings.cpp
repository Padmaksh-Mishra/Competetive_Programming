//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 

# include <bits/stdc++.h>

using namespace std;

# define PM ios_base::sync_with_stdio(false); 
# define IS cin.tie(NULL); 
# define LEGENDARY cout.tie(NULL);
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
# define For(i,a,b) for(ll i = a; i < b; ++i)

const ll MOD = 1e9 +7;

void setIO(string name = "sublime") {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}

void solve(){
	int n; cin >> n;
	vector<string> v(n);
	For(i,0,n) cin >> v[i];
	vector<int> ans;

	for(auto val1 : v){
		bool ok = false;
		for(auto val2 : v){
			for(auto vla3 : v){
				if(val1==(val2+vla3)){
					ok = true;
					break;
				}
			}
			if(ok) break;
		}
		if(ok) ans.pb(1);
		else ans.pb(0);

	}


	for(auto val : ans) cout << val;
		cout << endl;
}

int main(){

    PM IS LEGENDARY

    setIO();	//Google and other non judges

    int TC = 1;
    cin >> TC;
    For(i,0,TC){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

