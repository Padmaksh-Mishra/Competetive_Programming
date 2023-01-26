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
	vector<vll> univ(n+1,vll(1));
	vll stu(n);
	vector<pll> vp;
	for(int i=0;i<n;++i){
		cin >> stu[i];
	}	    
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		vp.emplace_back(make_pair(tmp,stu[i]));
	}
	sort(all(vp),greater<pll>());
	for(auto val : vp){
		ll tmp = val.f;
		ll s = val.s;
		univ[s].emplace_back(univ[s].back()+tmp);
	}
	vll ans(n+1);
	for(int u=0;u<siz(univ);++u){
		ll t = siz(univ[u])-1;
		for(int i=1;i<t+1;++i){
			ll indx = t%i;
			ans[i]+=(univ[u][t-indx]);
		}		
	}
	for(int i=1;i<n+1;++i){
		cout << ans[i] << " ";
	}
	cout << endl;
}
