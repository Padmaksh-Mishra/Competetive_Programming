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

set<int> s;
string dp[100001];
void karo(){
	// dp[0] = "0";
	// dp[1] = "10";
	for(int i=0;i<317;++i){
    	s.insert((i*i));
    }
    // for(int i=2;i<100001;++i){
    // 	string tmp = "";
    // 	auto it = s.lower_bound(i);
    // 	int x = *(it);
    // 	deb(x);
    // 	for(int j=i;j!=(x/2);--j){
    // 		tmp+=(j+'0');
    // 	}
    // 	dp[i] = dp[(x/2)-1] + tmp;
    // }
}
void solve(){
	int n; cin >> n;
	auto it = lower_bound(n);
	int x = *it;
	list<int> l;
	for(int i=(x-n-1);i>=0;--i) l.pb(i);
	int si = siz(l);
	for(int)
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
    int TC = 1;
    cin >> TC;

    karo();
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