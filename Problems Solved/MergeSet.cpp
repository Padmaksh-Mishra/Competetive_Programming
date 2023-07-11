# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (ll)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()
# define YES cout<<"Yes"<<endl
# define NO cout<<"No"<<endl

//Namespaces
using namespace __gnu_pbds;
using namespace std;

//Templates
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>; //less_equal=ms can have duplicates
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(K): Kth element in a Set (counting from zero).

//Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const ll N = 2e5 + 1;   

//For fileIO
void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

//bexpo
ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve();

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    //setIO("sublime");        
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n,m; cin >> n >> m;
    vector<vector<pll>> graph(m+1,vector<pll>());
    vector<vll> store(n,vll());
    for(int i=0;i<n;++i){
    	ll a; cin >> a;
    	ll t; cin >> t;
    	store[i].emplace_back(t);
    	for(int j=1;j<a;++j){
    		ll e; cin >> e;
    		store[i].emplace_back(e);
    		graph[t].emplace_back(make_pair(e,1));
    	}
    }
    for(auto val : store){
    	ll t = val[0];
    	for(int i=1;i<siz(val);++i){
    		graph[]
    	}
    }
    deque<ll> q;
    q.push_back(1);
    vll visited(m+1,0);
    vll dist(m+1,INF);
    dist[1] = 0;
    while(!q.empty()){
    	ll tmp = q.front();
    	q.pop_front();
    	visited[tmp] = 1;
    	for(auto c : graph[tmp]){
    		if(visited[c.f]) continue;
    		if(c.s){
    			dist[c.f] = min(dist[tmp] + 1,dist[c.f]);
    			q.push_back(c.f);
    		}else q.push_front(c.f);
    	}
    }
    if(dist[m]!=INF) cout << dist[m] << endl;
    else cout << -1 << endl;
}
