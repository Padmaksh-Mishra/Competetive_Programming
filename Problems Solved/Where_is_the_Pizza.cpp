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
	vll a(n+1),b(n+1),d(n+1),pos(n+1),vis(n+1,0);
	for(int i=1;i<=n;++i) cin >> a[i],pos[a[i]] = i;
	for(int i=1;i<=n;++i) cin >> b[i];    	
	for(int i=1;i<=n;++i) cin >> d[i];
	ll ans = 1;
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			ll x = i;
			bool flag = 0;
			while(!vis[x]){
				vis[x] = 1;
				flag|=(d[x]>0);
				x = pos[b[x]];
			}
			if(!flag&&a[i]!=b[i]) ans = (ans*2)%MOD;
		}
	}
	cout << ans << endl;
}
