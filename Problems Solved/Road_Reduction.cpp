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
struct edge{
	ll i,j,w,idx;
};
void solve(){
    ll n,m; cin >> n >> m;
    vector<pll> graph[n+1];
    map<pll,ll> mpp;
    for(int i=0;i<m;++i){
    	ll a,b,w; cin >> a >> b >> w;
    	graph[a].emplace_back(make_pair(b,w));
    	graph[b].emplace_back(make_pair(a,w));
    	mpp[make_pair(min(a,b),max(a,b))] = i+1;
    }
    vll dist(n+1,INF);
    vll idx(n+1);
    dist[1]=0;
   	priority_queue<pll,vector<pll>,greater<pll>> pq;
   	pq.push(make_pair(0,1));
   	while(!pq.empty()){
   		ll a = pq.top().s;
   		ll w = pq.top().f;
   		pq.pop();
   		if(dist[a]!=w) continue;
   		for(auto child : graph[a]){
   			ll b = child.f;
   			ll wt = child.s;
   			if(dist[b]>dist[a]+wt){
   				dist[b] = dist[a]+wt;
   				idx[b] = mpp[make_pair(min(a,b),max(a,b))];
   				pq.push(make_pair(dist[b],b));
   			}
   		}
   	}
   	set<ll> ans;
   	for(int i=1;i<n+1;++i){
   		if(idx[i]==0) continue;
   		ans.insert(idx[i]);
   	}
   	for(auto val : ans){
   		cout << val << " ";
   	}
   	cout << endl;
}
