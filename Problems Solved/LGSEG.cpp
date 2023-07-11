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
    ll n,k,s; cin >> n >> k >> s;
    vll ps(n);
    vector<vll> up(n+1,vll(20));

    ps[0] = 0;
    for(int i=0;i<n;++i){
    	ll t; cin >> t;
    	if(i>0) ps[i] = ps[i-1] + t;
    	else ps[i] = t;
    }
    for(int i=0;i<n;++i){
    	ll t = upper_bound(all(ps),ps[i]+s) - ps.begin();
    	up[i][0] = min(t,n);
    	// deb(up[i][0]);
    }
    up[n+1][0] = n+1;
    for(int i=0;i<19;++i){
    	for(int j=0;j<n;++j){
    		up[j][i+1] = up[ up[j][i] ][i];
    	}
    }
    ll ml = 0;
    for(int i=0;i<n;++i){
    	ll j = i;
    	for(int i=19;i>-1;--i){
    		if(k&(1<<i)){
    			j = up[j][i];
    		}
    	}
 		// deb(ps[j]);
    	// deb(j);
    	ml = max(ml,j-i);
    }
    cout << ml << endl;
}
