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
	vector<pll> v(4);
	ll tmp; 
	
	cin >> tmp;
	v[0].f = tmp;
	v[0].s = 0;
	
	cin >> tmp;
	v[1].f = tmp;
	v[1].s = 1;
	
	cin >> tmp;
	v[3].f = tmp;
	v[3].s = 3;
	cin >> tmp;
	v[2].f = tmp;
	v[2].s = 2;

	sort(all(v));
	if(abs(v[3].s-v[0].s)==2) cout << "YES" << endl;
	else cout << "NO" << endl;
}
