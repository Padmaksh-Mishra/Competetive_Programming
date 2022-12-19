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
	int m; cin >> m;
	vector<int> a[n];
	for(int i = 0;i<n;++i){
		for(int j=0;j<m;++j){
			int tmp; cin >> tmp;
			a[i].pb(tmp);
			//deb(a[i][j]);
		}
	}
	int ans = -1;
	for(int r=0;r<n;++r){
		for(int c=0;c<m;++c){
			int tmp = 0;
			int ct=c,rt=r;
			while(ct>=0&&ct<m&&rt>=0&&rt<n){
				tmp+=a[rt][ct];
				rt++;
				ct++;
			}
			ct=c,rt=r;
			while(ct>=0&&ct<m&&rt>=0&&rt<n){
				tmp+=a[rt][ct];
				rt++;
				ct--;
			}
			ct=c,rt=r;
			while(ct>=0&&ct<m&&rt>=0&&rt<n){
				tmp+=a[rt][ct];
				rt--;
				ct++;
			}
			ct=c,rt=r;
			while(ct>=0&&ct<m&&rt>=0&&rt<n){
				tmp+=a[rt][ct];
				rt--;
				ct--;
			}
			tmp-=(a[r][c]*3);
			ans = max(ans,tmp);
		}
	}
	cout << ans << endl;
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