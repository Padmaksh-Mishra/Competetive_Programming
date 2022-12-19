# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll k; cin >> k;
	ll tmp = k;
	ll ans = -1;
	for(int i=2;(i*i)<=k;++i){
		ll fac = 0;
		while(tmp%i==0){
			fac++;
			tmp/=i;
		}
		ll n = 0;
		while(fac>0){
			n += i;
			ll x = n;
			while(x%i==0){
				fac--;
				x/=i;
			} 
		}
		ans = max(ans,n);
	}	
	ans = max(ans,k);
	cout << ans << endl;
}
