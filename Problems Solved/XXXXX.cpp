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
	vi ip(n);
	for(int i=0;i<n;++i) cin >> ip[i];
	vll ps(n+1);
    ps[0] = 0;
    for(int i=1;i<=n;++i){
    	ps[i] = ps[i-1] + ip[i-1];
    }
    for(int i=1;i<=n;++i){
    	if(ps[i]%x!=0) ps[i]=1;
    	else ps[i]=0;
    }
    
	int far = -1;
	for(int i=1;i<=n;++i){
		if(ps[i]==1) {
			far = i;
			break;
		}
	}
	for(int i=n;i>0;--i){
		if(ps[i]==1) {
			far = min(n-i,far);
			break;
		}
	}
	if(far!=-1) far = n-far;
	cout << far << endl;
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