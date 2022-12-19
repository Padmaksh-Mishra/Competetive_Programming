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
	ll k,n; cin >> n >> k;
	vector<pll> ips;
	for(int i=0;i<n;++i){
		ll s,e; cin >> s >> e;
		ips.emplace_back(make_pair(s,e));
	}
	sort(all(ips),[](pll a,pll b)->bool{return a.s<b.s;});
	multiset<ll,greater<ll>> m;
	ll ans = 0;
	for(int i=0;i<n;++i){
		ll s = ips[i].f,e = ips[i].s;
		//cout << s << " " << e << endl;
		auto it = m.lower_bound(s);
		if(it!=m.end()){
			m.erase(it);
			m.insert(e);
		}else{
			if(m.size()==k){
				ans++;
			}else m.insert(e);
		}
	}	    
	cout << n-ans << endl;
}
