// <--> Nefarious <--> BadNess is in my ass

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;


void solve(){
	int n; cin >> n;
	ll ans = 0;
	int tmp;
	int ones=0;
	for(int i=0;i<n;++i){
	    cin >> tmp;
	    if(tmp==0){
	        ans += ones*(ones+1)/2;
	        ones = 0;
	   }else ones++;
	   
	}
	ans += ones*1LL*(ones+1)/2;
	cout << ans << endl;
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

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}
