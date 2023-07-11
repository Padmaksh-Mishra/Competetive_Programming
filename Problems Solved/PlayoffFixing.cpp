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
const ll MOD = 998244353;
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
    ll k; cin >> k;
    // k++;
    vll tree((1<<(k+1)),-1);
    for(int i=(1<<(k));i<(1<<(k+1));++i) cin >> tree[i];
    ll ans = 1;
	
    for(int lvl=k;lvl>0;--lvl){
    	ll miv = (1<<(lvl-1));
    	ll fact = 0;
    	ll pot = 1;
    	// deb(miv);
    	for(int v=(1<<lvl);v<(1<<(lvl+1));v+=2){
    		// cout << tree[v] << " " << tree[v+1] << endl;
    		ll mx = max(tree[v],tree[v+1]);
    		ll ix = min(tree[v],tree[v+1]);
    		if(tree[v]==-1&&tree[v+1]==-1){
    			pot*=2;
    			fact++;
    		}else if(tree[v]==-1||tree[v+1]==-1){
    			if(mx<miv+1){
    				tree[v/2] = mx;
    				fact++;
    			}
    		}else{
    			if(mx<miv+1){
    				cout << 0 << endl;
    				return;
    			}else{
    				tree[v/2] = ix;
    			}
    		}
    	}
    	ll fac = 1;
    	for(int i=1;i<fact+1;++i) fac = (fac*i)%MOD;
    	// deb(fac);
    	// deb(pot);
    	ans = (ans*(fac*pot)%MOD)%MOD;

    }
    cout << ans << endl;
}
