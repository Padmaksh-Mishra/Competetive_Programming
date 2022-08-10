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

using namespace std;
const ll MOD = 1e9 +7;
void setIO(string name = "sublime");



void solve(){
	int n,x; cin >> n >> x;
	vector<ll> prices(n);
	for(int i=0;i<n;++i) cin >> prices[i];
	sort(prices.begin(), prices.end());
	vector<ll> pa(n);
	pa[0] = prices[0];
	for(int i = 1;i<n;++i) pa[i] = prices[i] + pa[i-1];
	ll ans = 0;
	ll day = 0;
	int j = n-1;
	//int k = 4;
	while(true){
		ll cost = pa[j] + ((j+1)*day);
		while(j>=0&&cost>x) {
			j--;
			cost = pa[j] + ((j+1)*day);
		}
		day++;
		ans+=j+1;
		// deb(j); deb(cost); deb(day);
		if(pa[0]+day>x) break;
	}
	cout << ans << endl;	
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
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

//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 