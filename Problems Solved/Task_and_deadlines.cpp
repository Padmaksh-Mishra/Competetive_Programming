# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define eb emplace_back
# define mp make_pair
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()
# define pll pair<ll,ll>

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
	vector<pll> v(n);
	for(int i=0;i<n;++i){
		ll t,d; cin >> t >> d;
		v.eb(mp(t,d));
	}	    
	sort(all(v),[](pll a,pll b)->bool{return a.f<b.f;});
	ll ans=0,t = 0;
	for(auto val : v){
		t+=val.f;
		ans+=val.s-t;
	}
	cout << ans << endl;
}
