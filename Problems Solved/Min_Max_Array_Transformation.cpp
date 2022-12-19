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

void solve(){
	ll n; cin >> n;
	vll a(n),b(n),dmax(n),dmin(n);
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<n;++i) cin >> b[i];
	ll s=0;
	ll small = b[0];
	for(int i=0;i<n;++i){
		if(a[i]<=small) dmin[i] = small-a[i];
		else small = b[s+1],--i,++s;
	}
	ll big = b[n-1];
	a.pb(0);
	for(int i=n-1;i>=0;--i){
		if(b[i]>=a[i+1]) dmax[i] = big - a[i];
		else big = b[i],dmax[i] = big - a[i];
	}
	for(auto val : dmin) cout << val << " ";
	cout << endl;
	for(auto val : dmax) cout << val << " ";
	cout << endl;
}
