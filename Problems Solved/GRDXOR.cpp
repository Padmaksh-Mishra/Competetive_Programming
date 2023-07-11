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
    ll n,m; cin >> n >> m;
    vector<vll> mat(n,vll(m));
    vector<vll> cb(m,vll(32,0)),rb(n,vll(32,0));

    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		cin >> mat[i][j];
    		for(int k=0;k<32;++k){
    			rb[i][k]+=((mat[i][j]>>k)&1);
    		}
    	}
    }
    vll bs(32,0);
    for(int i=0;i<m;++i){
    	for(int j=0;j<n;++j){
    		for(int k=0;k<32;++k){
    			cb[i][k]+=((mat[j][i]>>k)&1);
    			if((mat[j][i]>>k)&1) bs[k]++;
    		}
    	}
    }
    ll fans = 0;
	for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		ll ans = 0;
    		// deb(mat[i][j]);
    		for(int k=0;k<32;++k){
    			bool set = ((mat[i][j]>>k)&1);
    			// deb(k);
    			if(set){
    				ll ns = n*m - bs[k];
    				ns-=(n-cb[j][k]+m-rb[i][k]);
    				// deb(ns);
    				ans+=(ns*(1ll<<k));
    			}else{
    				ll ss = bs[k];
    				ss-=(cb[j][k]+rb[i][k]);
    				// deb(ss);
    				ans+=(ss*(1ll<<k));
    			}
    		}
    		// deb(ans);
    		fans = max(fans,ans);
    	}
    }    
    cout << fans << endl;
}
