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
	string s; cin >> s;
	map<ll,ll> m;
	ll cnt = 1;
	ll po = -1;
	for(int i=0;i<n;++i){
		if(s[i]=='"'){
			if(cnt&1){
				po = i;
			}else{
				m[po] = i;
			}
			cnt++;
		}
	}
	//for(auto val : m) cout << val.f << " " << val.s << endl;
	for(int i=0;i<n;++i){
		if(s[i]=='"'){
			if(m[i]) i=m[i];
			if(i>=n) break;
		}
		if(s[i]==',') s[i] = '.';
	}
	cout << s << endl;
}
