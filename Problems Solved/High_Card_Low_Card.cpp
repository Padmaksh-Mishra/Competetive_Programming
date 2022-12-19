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
	ll n; cin >> n;
	set<ll> a;
	vll bc;
	for(int i=0;i<2*n;++i){
		a.insert(i+1);
	}	    
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		bc.emplace_back(tmp);
		a.erase(a.find(tmp));
	}
	ll ans = 0;
	set<ll> fh,sh;
	ll i=0;
	for(auto val : a){
		if(i<n/2) sh.insert(val);
		else fh.insert(val);
		++i;
	}
	for(int i=0;i<n;++i){
		//deb(bc[i]);
		if(i<n/2){
			auto it = fh.upper_bound(bc[i]);
       		if(it!=fh.end()){
       			ans++;
       			fh.erase(it);
       		}else fh.erase(fh.begin());
       	}else {
       		auto it = sh.upper_bound(bc[i]);
			if(it!=sh.begin()){
				ans++;
				sh.erase(--it);
			}else sh.erase(--sh.end());   
       	}           
	}
	cout << ans << endl;
}
