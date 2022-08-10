//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 

# include <bits/stdc++.h>
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

using namespace std;
const ll MOD = 1e9 +7;

void setIO(string name = "sublime");
void define();
void solve(){
	int n; cin >> n;
	vector<string> grid(n);
	For(i,0,n){
		cin >> grid[i];
	}
	int ops = 0;
	For(i,1,(n+1)/2){
		For(j,1,n/2){
			int o=0;
        	if(grid[i][j]=='1')o++;
    		if(grid[j][n-i]=='1')o++;
    		if(grid[n-i][n-j]=='1')o++;
    		if(grid[n-i][j]=='1')o++;
    	
			ops+=min(o,4-o);        		
		}
	}
	cout << ops << endl;
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

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}

void define(){

}
																							