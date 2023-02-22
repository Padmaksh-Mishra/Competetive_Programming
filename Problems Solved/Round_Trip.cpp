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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,m; cin >> n >> m;
	vll graph[n];
	while(m--){
		ll a,b; cin >> a >> b;
		a--,b--;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}	    
	bool cycle = false;
	vll par(n);
	vll vis(n);
	auto bfs = [&](ll v){
		queue<ll> q;
		q.push(v);
		while(!q.empty()){
			ll node = q.front();
			q.pop();
			for(auto child : graph[node]){
				deb(child);
				if(vis[child]){
					cycle = true;
					vll ans;
					while(child!=-1){
						ans.push_back(child);
						child = par[child];
					}
					deb(siz(ans));
					reverse(all(ans));
					for(auto val : ans){
						cout << val << " ";
					}
					cout << endl;
					return;
				}
				vis[child] = 1;
				par[child] = node;
				q.push(child);
			}
		}
	};
	for(int i=0;i<n;++i){
		if(cycle) return;
		fill(all(vis),0);
		fill(all(par),-1);
		vis[i] = 1;
		bfs(i);
	}
	cout << "IMPOSSIBLE" << endl;
}
