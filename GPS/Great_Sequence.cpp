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
	ll n,x; cin >> n >> x;

	multiset<ll> s;
	int tmp;
	for(int i=0;i<n;++i) {
		cin >> tmp;
		s.insert(tmp);
	}
	int ops = 0;
	for(auto it=s.begin();it!=s.end();++it){
		ll val = (*it)*x*1LL;
		//deb(val);
		auto itr = s.find(val);
		if(itr==s.end()){
			ops++;
		}else s.erase(itr);
	}
	cout << ops << endl;
	
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