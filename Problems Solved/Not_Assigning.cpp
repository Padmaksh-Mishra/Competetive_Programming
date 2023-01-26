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
	ll n; cin >> n;
	ll tmp = n-1;
	vector<pll> que;
	vector<ll> tree[n+1];
	vll vis(n+1);
	while(tmp--){
		ll a,b; cin >> a >> b;
		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
		que.emplace_back(make_pair(a,b));
	}	    
	for(int i=1;i<n+1;++i){
		if(siz(tree[i])>2){
			// deb(i);
			cout << -1 << endl;
			return;
 		}
	}
	map<pll,ll> m;
	function<void(ll v,ll c)> dfs = [&](ll v,ll c)->void{
		if(vis[v]) return;
		vis[v] = 1;
		for(auto child : tree[v]){
			pll tmp = make_pair(v,child);
			pll rtmp = make_pair(child,v);
			if(vis[child]) continue;
			dfs(child,(c^1));
			m[tmp] = c;
			m[rtmp] = c;
			c^=1;
		}
	};

	dfs(1,1);

	for(auto val : que){
		cout << m[val]+2 << " ";
	}
	cout << endl;
	
}
