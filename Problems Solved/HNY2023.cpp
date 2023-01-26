# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
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
vector<bool> is_prime(1e8+1, true);
vll primesq,primes;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	ll n = 1e8;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] && (long long)i * i <= n) {
	        for (ll j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	    }
	}
	for(ll i=0;i<n+1;++i){
		if(is_prime[i]){
			primesq.emplace_back(i*i*1ll);
			primes.emplace_back(i);
		}
	}
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 


void solve(){
	ll n; cin >> n;
	ll limit = 0;
	for(ll i=siz(primesq)-1;i>-1;--i){
		// if(sq>limit) break;
		// deb(sq);
		ll sq = primesq[i];
		if(n%sq==0){
			ll sec = n/sq;
			ll fir = sqrt(sq);
			//if(!is_prime[sec]) continue;
			cout << fir << " " << sec << endl;
			return;
		}
	}
	for(ll i=siz(primes)-1;i>-1;--i){
		ll prime = primes[i];
		if(n%prime==0){
			ll sec = (n/prime);
			ll fir = sqrt(sec);
			//if(!is_prime[sec]) continue;
			cout << fir << " " << prime << endl;
			return;
		}
	}
}
