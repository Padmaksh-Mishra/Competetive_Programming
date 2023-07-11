# include <bits/stdc++.h>
# define ll long long
# define pll pair<ll,ll>
# define vll vector<ll>
# define s second
# define f first
using namespace std;

ll INF = 1e18 + 9;

int main(){
	ll n,m; cin >> n >> m;
	vector<vector<pll>> graph(n,vector<pll>());
	vector<vector<pll>> rgraph(n,vector<pll>());
	for(int i=0;i<m;++i){
		ll a,b,w; cin >> a >> b >> w;
		graph[a-1].emplace_back(make_pair(b-1,-w));
		rgraph[b-1].emplace_back(make_pair(a-1,-w));
	}

	//bellman ford
	vector<ll> dis(n,INF);
	dis[0] = 0;
	for(int r=0;r<n-1;++r){
		for(int i=0;i<n;++i){
			for(auto &edge : graph[i]){
				if(dis[i]!=INF && dis[edge.f]>dis[i]+edge.s){
					dis[edge.f]=dis[i]+edge.s;
				}
			}
		}
	}
	vll cngd(n);
	for(int i=0;i<n;++i){
		for(auto &edge : graph[i]){
			if(dis[i]!=INF && dis[edge.f]>dis[i]+edge.s){
				cngd[edge.f] = 1;
				// cout << -1 << "\n";
				// return 0;
			}
		}
	}
	ll ans = -dis[n-1];
	vll vis(n);
	function<void(int)> dfs = [&](int v){
		if(vis[v]==1) return;
		vis[v] = 1;
		for(auto edge : graph[v]){
			dfs(edge.f);
		}
	};
	dfs(0);
	vll rvis(n);
	function<void(int)> rdfs = [&](int v){
		if(rvis[v]==1) return;
		rvis[v] = 1;
		for(auto edge : rgraph[v]){
			rdfs(edge.f);
		}
	};
	rdfs(n-1);
	for(int i=0;i<n;++i){
		// cout << vis[i] << " " << rvis[i] << " " << cngd[i] << endl;
		if(vis[i]&&rvis[i]&&cngd[i]){
			ans = -1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}