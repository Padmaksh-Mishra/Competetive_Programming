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
# define vpll vector<pll>
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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    vector<vpll> tree(n+1,vpll());
    vll vis(n+1);
    vis[1]=1;
    unordered_map<ll,set<ll>> um;
    for(int i=0;i<n-1;++i){
        
        ll a,b; cin >> a >> b;

        um[a].insert(b);
        um[b].insert(a);
        ll ew = 1;
        if(vis[a]||vis[b]){
            if(!vis[a]) swap(a,b);
            ew = 0;
            vis[b]=1;
            for(auto s : um[b]) vis[s] = 1;
            um[b].clear();
        }
        tree[a].emplace_back(make_pair(b,ew));
        tree[b].emplace_back(make_pair(a,ew));
    }
    deque<ll> q;
    q.push_back(1);
    vll dpt(n+1);
    fill(all(vis),0);
    dpt[1] = 1;
    while(!q.empty()){
        ll x = q.front();
        q.pop_front();
        vis[x] = 1;
        for(auto c : tree[x]){
            if(vis[c.f]) continue;
            if(c.s==0) q.push_front(c.f);
            else q.push_back(c.f);
            dpt[c.f] = dpt[x] + c.s;
        }
    }
    cout << *max_element(all(dpt)) << endl;
}
