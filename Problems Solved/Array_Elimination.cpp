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
	ll n;cin >> n;
	vll a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}		    
	vll bits(32);
	ll finddivof = 0;
	for(int i=0;i<32;++i){
		for(auto val : a){
			ll tmp = (1<<i);
			bits[i]+=(val>>i)&1;
		}
		// deb(bits[i]);
		finddivof = __gcd(finddivof,bits[i]);
	}
	set<ll> ans;
	for(int i=1;i*i<finddivof+1;++i){
		if(finddivof%i==0){
			ans.insert(i);
			ans.insert(finddivof/i);
		}
	}
	if(siz(ans)==0){
		for(int i=1;i<n+1;++i){
			cout << i << " ";
		}
		return;
	}
	for(auto val : ans){
		cout << val << " ";
	}
	cout << endl;
}
