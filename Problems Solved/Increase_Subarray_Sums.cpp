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
	ll n,x; cin >> n >> x;
	vll psum(n+1);
	psum[0] = 0;
	for(int i=1;i<=n;++i){
		ll tmp; cin >> tmp;
		psum[i] += psum[i-1] + tmp;
	}
	auto maxs = [&](ll window)->ll{
		ll ans = -INF;
		for(int i=0;i<=n-window;++i){
			ans = max(ans,psum[i+window]-psum[i]);
		}
		return ans;
	};	    
	vll store(n+1,0);
	for(int i=1;i<=n;++i){
		store[i] = maxs(i);
	}
	ll ans = 0;
	for(int k=0;k<=n;++k){
		for(int window = 1;window<=n;++window){
			ans = max(ans,store[window] + min(window,k)*x);
		}
		cout << ans << " ";
	}
	cout << endl;
}
