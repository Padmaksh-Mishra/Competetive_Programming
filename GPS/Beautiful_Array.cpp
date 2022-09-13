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

void solve(){
	ll n,k,b,s; cin >> n >> k >> b >> s;
    vll ans(n,0);

    ll sm = k*b;
    ans[0] = sm;
	ll extras = s-(sm);
	if(extras>0){
		for(int i=1;i<n;++i){
			ll tmp = min(k-1,extras);
			ans[i]+=tmp;
			sm+=tmp;
			extras-=tmp;
		}
	}
	if(extras>0||sm!=s){
		cout << -1 << endl;
		return;
	}
	for(auto val : ans){
    	cout << val << " ";
    }
    cout << endl;
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