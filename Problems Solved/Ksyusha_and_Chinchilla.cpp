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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    vector<vll> tree(n,vll());
    map<pll,ll> um;
    for(int i=0;i<n-1;++i){
    	ll a,b; cin >> a >> b;
    	um[make_pair(a-1,b-1)] = i+1;
    	um[make_pair(b-1,a-1)] = i+1;
    	a--,b--;
    	tree[a].emplace_back(b);
    	tree[b].emplace_back(a);
    }
    vll v(n);
    vll vis(n);
    vll ans;
    function<void(ll,ll)> dfs = [&](ll k,ll p){
    	if(vis[k]) return;
    	vis[k] = 1;
    	for(auto c : tree[k]){
    		if(c==p) continue;
    		dfs(c,k);
    		v[k]+=(v[c]);
    	}
    	v[k]++;
    	if(v[k]==3){
    		v[k]=0;
    		ans.emplace_back(um[make_pair(k,p)]);
    	}
    };
    dfs(0,-1);
    if(v[0]==0){
    	cout << siz(ans)-1 << endl;
    	for(auto val : ans){
    		if(val==0) break;
    		cout << val << " ";
    	}
    	cout << endl;
    }else cout << -1 << endl;
}
