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
	ll n; cin >> n;
	ll diff = 0;
	vll ips(n),a;
	bool aaz = true;	
	map<ll,ll> m;
	for(int i=0;i<n;++i){
		cin >> ips[i];
		m[ips[i]]++;
		if(ips[i]!=0) aaz = false;
	}
	for(int i=0;i<n;++i){
		if(m[ips[i]]==1) a.pb(ips[i]);
	}
	sort(all(a),greater<ll>());
	for(int i=0;i<siz(a);++i){
		ll tmp = a[i];
		diff = abs(tmp-diff);
		// deb(diff);
	}    
	if(aaz) cout << 0 << endl;
	else cout << ((diff==0)? 1 : abs(diff)) << endl;
}
