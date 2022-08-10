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
	int n,q; cin >> n >> q;
	vll v(n);
	ll sum = 0;
	map<ll,ll> m;
	for(int i=0;i<n;++i) cin >> v[i],sum+=v[i];
	while(q--){
		int t; cin >> t;
		if(t==2){
			m.clear();
			ll x; cin >> x;
			sum = n*x*1LL;
			m[0] = x;
		}else{
        	ll i,x; cin >> i >> x;
        	if(m[0]!=0){
        		if(m[i]==0){
        			sum+=(x-m[0]);
        			m[i]=x;
        		}else{
        			sum+=(x-m[i]);
        			m[i]=x;
        		}
        	}else{
        		sum+=(x-v[i-1]);
        		v[i-1] = x;
        	}
		}
		cout << sum << endl;
	}

}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
    int TC = 1;
    //cin >> TC;
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