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
	vector<vll> v(n,vll(n));
	for(int i=0;i<n;++i){
		for(int j=0;j<n-1;++j){
			ll tmp; cin >> tmp;
			tmp--;
			v[j][tmp]++;
		}
	}	    
	vll ans(n);
	vector<pll> val(n);
	for(int i=0;i<n;++i){
		ll tmp = 0;
		for(int j=0;j<n;++j){
			tmp+=v[j][i]*j;
			val[i] = make_pair(tmp,i);
		}
	}
	sort(all(val));
	for(int i=0;i<n;++i){
		cout << val[i].s+1 << " " ;
	}
	cout << endl; 
}
