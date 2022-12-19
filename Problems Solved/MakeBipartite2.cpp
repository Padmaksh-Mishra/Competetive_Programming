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
vector<vll> graph(N);
vll color(N);
ll ans1 = 0, ans2 = 0;
void isBipartite(ll n){ 
    queue<pll> q;
    for (int i = 0; i < n; i++) {
    	ll nob = 1,now = 0;
    	bool ok = 1;
    	if(siz(graph[i])==0) continue;
        if (color[i] == -1) {
            q.push({ i, 0 });
            color[i] = 0;
           
            while (!q.empty()) {
                pll p = q.front();
                q.pop();
                ll v = p.first;
                ll c = p.second;
                for (ll j : graph[v]) {
                    if (color[j] == c){
                        ok = 0;
                        break;
                    }
                    if (color[j] == -1) {
                        color[j] = (c) ? 0 : 1;
                        nob+=(color[j]==0);
                        now+=(color[j]==1);
                        q.push({j,color[j]});
                    }
                }
            }
        }
        if(ok){
	        ans1+=(now*nob)/2;
	        ans2+=(now+nob)*(n-now-nob)/2;
    	}
    }
}

void solve(){
	ll n,m; cin >> n >> m;
	while(m--){
		ll a,b; cin >> a >> b;
		graph[a-1].emplace_back(b-1);
		graph[b-1].emplace_back(a-1);
	}
	fill(color.begin(),color.begin()+n,-1);
	// for(int i=1;i<=n;++i) cout << color[i] << " ";
	// cout << endl;
	
	cout << (ans1 + (ans2/2) - m) << endl;
}
