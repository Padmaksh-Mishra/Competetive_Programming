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

void dfs(ll p,vector<vll> &tree,vll &vis,vll &hight){
	if(vis[p]) return;
	else vis[p] = 1;
	for(auto child : tree[p]){
		if(vis[child]) continue;
		dfs(child,tree,vis,hight);
		hight[p] = max(hight[p],hight[child] + 1);
	}
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void solve(){
	ll n;cin >> n;
	vector<vll> tree(n + 1);
	vll vis(n+1);
	vll hight(n+1);

	fill(all(hight),0);
	for(int i=0;i<n-1;++i){
		ll a,b; cin >> a >> b;
		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}	    
	ll ans = 0;
	ll mul = binpow(2,n-1,MOD);
	dfs(1,tree,vis,hight);
	for(int i=1;i<n+1;++i){
		ans=(ans+mul*(hight[i]+1))%MOD;
		// deb(hight[i]);
	}
	cout << ans%MOD << endl;
}
