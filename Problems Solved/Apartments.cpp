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
    setIO("sublime");    //Does not work with Google     
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
	ll n,m,k; cin >> n >> m >> k;
	vll a(n),b(m);
	for(int i=0;i<n;++i) cin >> a[i];
	for(int i=0;i<m;++i) cin >> b[i];
	sort(all(a));
	sort(all(b));
	ll ans = 0;
	for(int i=0,j=0;i<m&&j<n;){
		if(abs(a[j]-b[i])<=k){
			ans++;
			j++;
			i++;
		}else if(a[j]-b[i]>k) i++;
		else if(b[i]-a[j]>k) j++; 
	}
	cout << ans << endl; 	    
}
