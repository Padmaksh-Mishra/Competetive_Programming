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
# define For(i,a,b) for(ll i = a; i < b; i++)

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
	int n,s,k; cin >> n >> k >> s;
	cout << k-1 + min(n+1,k-s+n-s+1) << endl;
}

int main(){

    PM IS LEGENDARY

    //setIO();

    int TC = 1;
    cin >> TC;
    For(i,0,TC){
    	cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

