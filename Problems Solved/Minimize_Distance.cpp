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
	vll ltz,gtz;
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		if(tmp<0) ltz.emplace_back(-tmp);
		else gtz.emplace_back(tmp);
	}	    
	sort(all(gtz));
	sort(all(ltz));
	multiset<ll> ms;
	// for(auto val : gtz) cout << val << " ";
	// cout << endl;
	// for(auto val : ltz) cout << val << " ";
	// cout << endl;
	while(siz(gtz)){
		ll tmp = *prev(gtz.end());
		ms.insert(tmp);
		if(siz(gtz)>k) gtz.erase(gtz.end()-k,gtz.end());
		else gtz.clear();
		// deb(siz(gtz));
		// deb(siz(ms));
	}
	while(siz(ltz)){
		ll tmp = *prev(ltz.end());
		ms.insert(tmp);
		if(siz(ltz)>k) ltz.erase(ltz.end()-k,ltz.end());
		else ltz.clear();
		// deb(siz(ltz));
		// deb(siz(ms));
	}
	ll ans = 0;
	for(auto val : ms){
		// cout << val << " ";
		ans+=2*val;
	}
	//cout << endl;
	cout << ans - *(prev(ms.end())) << endl;
	// cout << endl;
	// cout << endl;
}
