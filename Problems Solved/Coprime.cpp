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

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
ll gcd(ll a, ll b)
{
    /* GCD(0, b) == b; GCD(a, 0) == a,
       GCD(0, 0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    /*Finding K, where K is the
      greatest power of 2
      that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
 
    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;
 
    /* From here on, 'a' is always odd. */
    do
    {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;
 
        /* Now a and b are both odd.
           Swap if necessary so a <= b,
           then set b = b - a (which is even).*/
        if (a > b)
            swap(a, b); // Swap u and v.
 
        b = (b - a);
    }while (b != 0);
 
    return a << k;
}

void solve(){
	ll n; cin >> n;
	vector<pair<ll,ll>> s;
	map<ll,ll> st;
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		st[tmp]=i;
	}
	for(auto val : st){
		s.pb(make_pair(val.f,val.s));
	}
	ll sum = -1;
	n = siz(s);
	for(ll i=0;i<n;++i){
		for(ll j=0;j<n;++j){
			if(gcd(s[i].f,s[j].f)==1){
				sum = max(sum,s[i].s+s[j].s+2);
			}
		}
	} 
	cout << sum << endl;   
}
