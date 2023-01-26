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
	for(int i=0;i<m;++i){
		ll a,b; cin >> a >> b;
		a--,b--;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}	    
	queue<ll> q;
	q.push(0);
	vll par(n,-1),vis(n);
	while(!q.empty()){
		ll tmp = q.front();
		q.pop();
		vis[tmp] = 1;
		for(auto child : graph[tmp]){
			if(!vis[child]&&par[child]==-1){
				par[child] = tmp;
				q.push(child);
			}
		}
	}
	vll ans;
	ll tmp = n-1;
	while(tmp!=-1){
		ans.emplace_back(tmp);
		tmp = par[tmp];
	}
	if(siz(ans)==1){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << siz(ans) << endl;
	reverse(all(ans));
	for(auto val : ans){
		cout << val+1 << " ";
	}
	cout << endl;
}
