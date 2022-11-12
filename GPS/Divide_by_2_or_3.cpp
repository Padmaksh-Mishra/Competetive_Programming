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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}
bool killr = false;
// Do something good 
ll nott(ll n){
	ll ans = 0;
	while(n%3==0){
		n/=3;
		ans++;
	}
	while(n%2==0){
		n/=2;
		ans++;
	}
	if(n!=1) killr = true;
	return ans;
}
void solve(){
	ll n; cin >> n;
	vll ips(n);
	for(int i=0;i<n;++i){
		cin >> ips[i];
	}    
	sort(all(ips));
	ll g = 0;
	for(int i=0;i<n;++i){
		g = __gcd(g,ips[i]);
	}
	ll moves = 0;
	for(int i=0;i<n;++i){
		killr = false;
		moves+=nott(ips[i]/g);
		if(killr){
			cout << -1 << endl;
			return;
		}
	}
	cout << moves << endl;
}
