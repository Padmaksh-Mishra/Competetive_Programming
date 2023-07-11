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
    ll n; cin >> n;
    vector<set<ll>> sky(n,set<ll>());
    for(int i=0;i<n-1;++i){
    	ll a,b; cin >> a >> b;
    	a--,b--;
    	sky[a].insert(b);
    	sky[b].insert(a);
    }
    vll ans;
    vll vis(n);
    for(int i=0;i<n;++i){
    	if(siz(sky[i])>2){
    		vis[i] = 1;
    		ans.emplace_back(siz(sky[i]));
    		for(auto c : sky[i]){
    			vis[c]=1;
    			if(siz(sky[c])==2){
    				for(auto val : sky[c]){
    					if(val!=i){
    						sky[c].erase(sky[c].find(val));
    						sky[val].erase(sky[val].find(c));
    						break;
    					}
    				}
    			}
    		}
    	}
    }
    ll tmp = 0;
    for(int i=0;i<n;++i){
    	if(vis[i]) continue;
    	// if(siz(sky[i])>2){
    	// 	cout << "Kuch galat hai" << endl;
    	// }
    	tmp++;
    	// if(siz(sky[i])==2){
    	// 	tmp++;
    	// }
    	// if(siz(sky[i])==0) ans.emplace_back(0);
    }
    // tmp+=2;
    ll x = tmp%3;
    if(x==2) ans.emplace_back(1);
    else if(x==1) ans.emplace_back(0);
    tmp/=3;
    while(tmp--) ans.emplace_back(2);
    sort(all(ans));
    for(auto lvl : ans) cout << lvl << " ";
    cout << endl;
}
