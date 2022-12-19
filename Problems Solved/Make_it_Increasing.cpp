//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e18 +7;
using namespace std;

ll bexpo(ll n,ll p);
ll a[5000],b[5000];

void solve(){
	ll n; cin >> n;
	for(ll i = 0;i<n;i++) cin >> a[i] , b[i] = 0;    
	ll mincount = MOD,count = 0;
	ll tmp = 0;
	for(ll i = 0;i<n;i++){
		b[i] = 0;
		for(ll k = i-1;k>=0;k--){
			tmp = abs(b[k+1]/a[k]);
			tmp++;
			b[k] = -(tmp*a[k]);
			count+=tmp;
		}
		for(ll k = i+1;k<n;k++){
			tmp = b[k-1]/a[k];
			tmp++;
			b[k] = (tmp*a[k]);
			count+=tmp;	
		}
		mincount = min(mincount,count);
		count = 0;
	}
	cout << mincount << endl;	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    ll TC = 1;
    //cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
ll bexpo(ll n,ll p){ 
    ll ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
