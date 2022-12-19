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
	ll m; cin >> m;
	ll h = log2(m);
	queue<ll> ips;
	for(int i=0;i<m;++i) {
		int t;
		cin >> t;
		ips.push(t);
	}
	ll swp = 0;
	for(int i=1;i<=h;++i){
		ll t = (1<<(i-1));
		// deb(t);
		for(int j=0;j<(m/t);j+=2){
			ll a = ips.front();
			ips.pop();
			ll b = ips.front();
			ips.pop();
			// deb(a);
			// deb(b);
			if(abs(a-b)!=(ll)(pow(4,i-1))){
				cout << -1 << endl;
				return;
			}
			if(a>b) swp++;
			ips.push(a+b);
		}
	}
	cout << swp << endl;
	return;
}
