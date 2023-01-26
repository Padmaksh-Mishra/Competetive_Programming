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
    setIO("cowjog");    //Does not work with Google     
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
	ll n,t; cin >> n >> t;
	vector<pll> v;
	for(int i=0;i<n;++i){
		ll a,b; cin >> a >> b;
		v.emplace_back(make_pair(a,a+b*t));
	}
	multiset<ll,greater<ll>> s;

	for(auto val : v){
		auto it = s.upper_bound(val.s);
		if(it!=s.end()){
			s.erase(it);
		}
		s.insert(val.s);
	}
	cout << siz(s) << endl;	    
}
