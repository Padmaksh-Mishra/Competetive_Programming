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
	int n; cin >> n;
	int x,y,xp,yp,xn,yn;
	xp=yp=xn=yn=0;
	vi v;
	while(n--){
		cin >> x >> y;
		if(x>0) xp=max(x,xp);
		else xn=max(-x,xn);

		if(y>0) yp=max(y,yp);
		else yn=max(-y,yn);
	}
    // v.pb(xp);
    // v.pb(xn);
    // v.pb(yp);
    // v.pb(xn);
    // sor(v);
    cout << 2*(xn+xp+yn+yp) << endl;
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