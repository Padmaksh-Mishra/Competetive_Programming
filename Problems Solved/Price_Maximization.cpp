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
	ll n,k; cin >> n >> k;
	multiset<ll> rems;
	ll ans = 0;
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		ans+=(tmp/k);
		rems.insert((tmp%k));
	}
	while(siz(rems)){
		auto it = rems.begin();
		ll val = *it;
		rems.erase(it);
		ll val2 = -1;
		auto it2 = rems.lower_bound(k-val);
		if(it2!=rems.end()){
			ans++;
			val2 = *it2;
			rems.erase(it2);
		}else{
			rems.erase(rems.begin());
		}
		// cout << val << " " << val2 << endl;
	}
	cout << ans << endl;
}
