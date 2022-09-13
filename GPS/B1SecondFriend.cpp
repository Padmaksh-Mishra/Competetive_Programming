# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
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
const int N = 1e5 + 1;

void setIO(string name = "sublime");

void solve(){
	int r,c; cin >> r >> c;
	vector<string> v(r);
	for(int i=0;i<r;++i) cin >> v[i];
	if(r==1||c==1){
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(v[i][j]=='^'){
					cout << "Impossible";
					return;
				}
			}
		}
		cout << "Possible" << endl;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				cout << '.';
			}
			if(i!=r-1)cout << endl;
		}
		return;
	}
	cout << "Possible" << endl;
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
				cout << '^';
		}
		if(i!=r-1)cout << endl;
	}
}

int main(){

    JAI SHREE RAM

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	cout << "Case #" << i+1 << ": ";
    	solve();
    	if(i!=TC-1)cout << endl;
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

//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 