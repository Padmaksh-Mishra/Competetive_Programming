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

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}
vll primes;
void solve();
void SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
 
    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p]) primes.pb(p);
}
int main(){
	SieveOfEratosthenes(2000001);
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
	 ll n; cin >> n;
	 vll ips(n),odd,even;
	 ll oc=0;
	 for(int i=0;i<n;++i){
	 	cin >> ips[i];
	 	if(ips[i]&1) odd.pb(ips[i]);
	 	else even.pb(ips[i]);	

	 	if(ips[i]==1) oc++;	
	 }   
	 if(oc>1){
	 	for(auto ev : even){
	 		if(binary_search(all(primes),ev+1)){
	 			cout << oc+1 << endl;
	 			while(oc--) cout << 1 << " ";
	 			cout << ev << endl;
	 			return;
	 		}
	 	}
	 	cout << oc << endl;
	 	while(oc--) cout << 1 << " ";
	 	return;
	 }
	 for(auto od : odd){
	 	for(auto ev : even){
	 		if(binary_search(all(primes),ev+od)){
	 			cout << 2 << endl;
	 			cout << ev << " " << od << endl;
	 			return;
	 		}
	 	}
	 }
	 cout << 1 << endl;
	 cout << ips[0] << endl;
}
