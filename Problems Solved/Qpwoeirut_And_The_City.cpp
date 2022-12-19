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
const ll INF = 1e18 + 9;

void solve(){
	int n; cin >> n;
	vll v(n);
	for(int i=0;i<n;++i) cin >> v[i];
    ll ans = INF;
	if(n&1){
		ans=0;
    	for(int i=1;i<n;i+=2){
    		ans += max<ll>(max<ll>(v[i+1],v[i-1])+1-v[i],0);
    	}
	}else{
		int tmp=0;
		vll o,t;
		ll sum = 0;
		for(int i=2;i<n;i+=2){
    		sum+=(max<ll>(max<ll>(v[i+1],v[i-1])+1-v[i],0));
    		o.pb(sum);
    	}
    	sum = 0;
    	for(int i=1;i<n-1;i+=2){
    		sum+=(max<ll>(max<ll>(v[i+1],v[i-1])+1-v[i],0));
    		t.pb(sum);
    	}
    	int s = siz(o);
    	for(int i=0;i<siz(o);++i){
    		ans=min(t[i]+o[s-1]-o[i],ans);
    	}
    	ans = min(ans,o[s-1]);
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