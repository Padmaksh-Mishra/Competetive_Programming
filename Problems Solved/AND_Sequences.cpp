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
vll fact(N);
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    fact[0] = 1;
    for(int i=1;i<N;++i){
    	fact[i] = (fact[i-1]*i)%MOD;
    }
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
	vll v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}	    
	sort(all(v));
	ll mini = 0;
	for(int i=0;i<n;++i){
		if((v[i]&v[0])!=v[0]){
			cout << 0 << endl;
			return;
		} 
	}
	for(int i=0;i<n;++i){
		if(v[i]==v[0]) mini++;
		else break;
	}
	// deb(mini);
	ll ans = (mini*(mini-1))%MOD;
	ans = (ans*fact[n-2])%MOD;
	cout << ans << endl;
}