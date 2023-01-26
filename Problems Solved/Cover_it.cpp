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
	ll n,m; cin >> n >> m;
	vll tree[n];
	vll vis(n);
	vll color(n,-1);
	for(int i=0;i<m;++i){
		ll a,b; cin >> a >> b;
		tree[a-1].emplace_back(b-1);
		tree[b-1].emplace_back(a-1);
	}	    
	function<void(ll,ll)> dfs = [&](ll v,ll c)->void{
		if(vis[v]) return;
		else vis[v] = 1;
		color[v] = (c^1);
		for(auto child : tree[v]){
			dfs(child,(c^1));
		}
	};
	dfs(0,0);
	vll ans1,ans2;
	for(int i=0;i<n;++i){
		if(color[i]==0){
			ans1.emplace_back(i);
		}else{
			ans2.emplace_back(i);
		}
	}
	
	if(siz(ans1)>siz(ans2)){
		cout << siz(ans2) << endl;
		for(auto val : ans2){
			cout << val+1 << " ";
		}
		cout << endl;
	}else{
		cout << siz(ans1) << endl;
		for(auto val : ans1){
			cout << val+1 << ' ';
		}
		cout << endl;
	}
}
