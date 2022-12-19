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
	ll c,n; cin >> c >> n;
	multiset<ll> s;
	vector<pll> v;
	for(int i=0;i<c;++i){
		ll tmp; cin >> tmp;
		s.insert(tmp);
	}	  
	for(int i=0;i<n;++i){
		ll a,b; cin >> a >> b;
		v.emplace_back(make_pair(a,b));
	}
	sort(all(v),[](pll a,pll b)->bool{
		if(a.s==b.s){
			return a.f<b.f;
		}
		return a.s < b.s;
	});
	ll ans = 0;
	for(pll val : v){
		//cout << val.f << ' ' << val.s << endl;
		auto it = s.lower_bound(val.f);
		if(it!=s.end()&&(*it)<=val.s){
			ans++;
			s.erase(it);
		}
	}  
	cout << ans << endl;
}
