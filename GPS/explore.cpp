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
# define NO cout << "No" << endl
# define YES cout << "Yes" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;

void solve(){
	int n,m,t; cin >> n >> m >> t;
	vi A(n);
	for(int i=1;i<n;++i) cin >> A[i];
	vi B(n,0);
	for(int i=0;i<m;++i){
		int tmp,tm; cin >> tmp >> tm;
		B[tmp]=tm;
	}	
	t+=B[1];
	for(int i = 1;i<n;++i){
		if(t<=A[i]){
			NO;
			return;
		}
		t-=A[i];
		t+=B[i+1];
	}
	YES;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    //cin >> TC;
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