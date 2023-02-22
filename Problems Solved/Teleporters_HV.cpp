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
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Doing something good 

void solve(){
	ll n,c; cin >> n >> c;
	vll cost(n);
	set<pll> cs,ce;
	for(int i=0;i<n;++i){
		cin >> cost[i];
	}	   
	for(int i=0;i<n;++i){
		cs.insert(make_pair(cost[i]+i+1,i));
		ce.insert(make_pair(cost[i]+(n-i),i));
	} 
	ll ans = 0;
	auto calc = [n](set<pll> cs,set<pll> ce,ll c,pll rmthis)->ll{
		vll hsh(n,0);
		ll ans = 0;
		ll val = rmthis.f;
		ll ind = rmthis.s;
		c-=val;
		if(c>-1) ans++;
		cs.erase(rmthis);
		hsh[ind] = 1;
		while(true){
		if(siz(cs)<1||siz(ce)<1||c<0){
			break;
		}
		ll beg = cs.begin()->f;
		ll end = ce.begin()->f;
		// deb(beg);
		// deb(end);
		if(beg<end){
			ll indx = cs.begin()->s;
			if(hsh[indx]==0){
				hsh[indx] = 1;
				c-=beg;
				if(c>-1) ans++;	
			}
			cs.erase(cs.begin());
		}else{
			ll indx = ce.begin()->s;
			if(hsh[indx]==0){
				hsh[indx] = 1;
				c-=end;
				if(c>-1) ans++;
				}
			ce.erase(ce.begin());
			}
		}
		return ans;
	};
	for(auto it = cs.begin();it!=cs.end();++it){
		ll val = it->f;
		ll indx = it->s;
		ans = max(ans,calc(cs,ce,c,make_pair(val,indx)));
	}
	
	cout << ans << endl;
}