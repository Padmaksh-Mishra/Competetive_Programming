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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
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
	vll a(n),b(n);
	set<ll,greater<ll>> s;
	map<ll,ll> m;
	for(int i=0;i<n;++i){
		cin >> a[i];
		auto it = s.upper_bound(a[i]);
		if(it!=s.end()){
			m[a[i]] = m[*it];
		}else{
			m[a[i]] = i;
			s.insert(a[i]);
		}
	}	    
	for(int i=0;i<n;++i){
		cin >> b[i];
	}
	ll ans = INF;
	for(int i=0;i<n;++i){
		ans = min(ans,i+m[b[i]-1]);
	}
	cout << ans << endl;
}
