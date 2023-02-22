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
long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans = (ans*(n - r + i))%MOD;
        ans /= i;
    }

    return ans;
}
void solve(){
	ll n; cin >> n;
	string a,b; cin >> a;
	cin >> b;
	ll mul=1,diff=0;

	for(int i=0;i<n;++i){
		if(a[i]==b[i]){
			mul=(mul*2)%MOD;
		}else{
			diff++;
		}
	}	    
	// deb(difmul);
	if(diff%2){
		cout << 0 << endl;
		return;
	}
	ll ans = mul*(mul!=1) + C(diff,diff>>1)*(diff!=0);
	cout << ans << endl;
}
