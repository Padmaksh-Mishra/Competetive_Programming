# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

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
	cin.tie(NULL); 
	cout.tie(NULL);
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
	int n,m; cin >> n >> m;
	vector<pair<ll,ll>> v;
	for(int i=0;i<m;++i){
		ll a,b; cin >> a >> b;
		v.pb(make_pair(b,a));
	}    
	sort(all(v));
	vll cords(2*n);
	ll ans = 0;
	for(int i=0;i<2*n;++i){
		cords[i] = v[i].s;
		ans+=v[i].f;
	}
	sort(all(cords));
	cout << ans << endl;
	for(int i=0;i<n;++i){
		cout << cords[i] << " " << cords[2*n - i] << endl;
	}
	return;
}
