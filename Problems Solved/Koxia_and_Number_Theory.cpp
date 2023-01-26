# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (ll)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const ll N = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((ll)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(ll i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    ll k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
    while ((a & 1) == 0)
        a >>= 1;
 
    do
    {
        while ((b & 1) == 0)
            b >>= 1;
        if (a > b)
            swap(a, b); // Swap u and v.
 
        b = (b - a);
    }while (b != 0);
 
    return a << k;
}
void solve(){
	ll n; cin >> n;
	vll ips(n);
	for(ll i=0;i<n;++i){
		cin >> ips[i];
	}	  
	auto ok = [&](ll x)->bool{
		for(ll i=0;i<n;++i){
			for(ll j=i+1;j<n;++j){
				if(gcd(ips[i],ips[j])!=1){
					return false;
				}
			}
		}
		return true;
	};  
	ll s=0,e=1e18,mid;
	while(e-s>1){
		mid = s + ((e-s)>>1);
		if(ok(mid)){
			cout << "Yes" << endl;
			return;
		}else{
			s = mid+1;
		}
	}
	cout << "No" << endl;
}
