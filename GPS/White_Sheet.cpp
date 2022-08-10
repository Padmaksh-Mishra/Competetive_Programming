//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;
ll x[6],y[6];
ll bexpo(ll n,ll p);

ll areaOfll(ll i){
	ll xi = max<ll>(0,min<ll>(x[i+2],x[1])-max<ll>(x[i+1],x[0]));
	ll yi = max<ll>(0,min<ll>(y[i+2],y[1])-max<ll>(y[i+1],y[0]));
	ll areai = xi*yi*1LL;
	if(areai>0){
		x[0] = 
	}
	return areai;
}

void solve(){
	
	for(ll i=0;i<6;++i) cin >> x[i] >> y[i];
	ll areaOfWhite = (x[1]-x[0])*(y[1]-y[0]);

	// deb(areaOfWhite);

	areaOfWhite-=areaOfll(1);
	//deb(areaOfWhite);
	areaOfWhite-=areaOfll(3);
	//deb(areaOfWhite);
	// ll xi = max<ll>(0,min<ll>(x[5],x[3])-max<ll>(x[4],x[2]));
	// ll yi = max<ll>(0,min<ll>(y[5],y[3])-max<ll>(y[4],y[2]));
	// ll areai = xi*yi*1LL;
	// deb(areai);
	// areaOfWhite+=areai;
	// deb(areaOfWhite);
	if(areaOfWhite>0) cout << "YES" << endl;
	else cout << "NO" << endl;


}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

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