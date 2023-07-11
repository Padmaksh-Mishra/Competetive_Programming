# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define vpll vector<pll>
# define all(x) (x).begin(), (x).end()

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
const int N = 2e5 + 1;   

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
        cout << "Case " << i+1 << ": ";
        solve();
    }
    return 0;
}

// Doing something good 

void solve(){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    pll mac; cin >> mac.f >> mac.s;
    ll t; cin >> t;
    
    auto distance = [mac](ll x,ll y)->double{
    	double dist = ((x-mac.f)*(x-mac.f) + (y-mac.s)*(y-mac.s));
    	dist = sqrt(dist);
    	return dist;
    };

    ll max_radi = min({abs(mac.f-a),abs(mac.f-c),abs(mac.s-b),abs(mac.s-d)});
    vll v(2000001);
    v[max_radi+1]--;
    while(t--){
    	ll x,y; cin >> x >> y;
    	double r; cin >> r;
    	double dist = distance(x,y);
    	double s = (dist-r);
    	double e = (dist+r);
    	cout << s << ' ' << e << endl;
    	if(s<0) s = 0;
    	v[floor(s)+1]--;
    	v[floor(e)+1]++;
    }
    ll ans = 0,tmp = v[0];
    for(int i=1;i<2e3;++i){
    	deb(v[i]);
    	tmp+=v[i];
    	if(tmp>-1){
    		ans++;
    	}
    }
    cout << ans << endl;
}
