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
    ll n,m,k; cin >> n >> m >> k;
    vector<vll> v(n+1,vll(m+1));
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<m+1;++j){
    		cin >> v[i][j];
    	}
    }
    vector<vll> ps(n+1,vll(m+1));
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ps[i][j] = v[i][j] + ps[i - 1][j] +
			                  ps[i][j - 1] - ps[i - 1][j - 1];
		}
	}
    ll e = max(n,m);
    ll s=0;

	function<bool(ll)> ok = [&](ll d){
		for(int i=1;i<n+1;++i){
			for(int j=1;j<m+1;++j){
				if(v[i][j]!=0){
                    ll ix=max(i-d,1ll),iy=max(j-d,1ll);
                    ll mx=min(i+d,n),my=min(j+d,m);
                    ll sum = ps[mx][my] - ps[mx][iy-1] - ps[ix-1][my] + ps[ix-1][iy-1];
                    // deb(sum);
                    if(sum>k) return true;
                }
			}
		}
		return false;
	};    
    while(e-s>1){
    	ll mid = s + (e-s)/2;
    	// deb(mid);
    	if(ok(mid)){
    		e=mid;
    	}else s = mid+1;
    }
    if(ok(s)){
        cout << s << endl;
    }else if(ok(e)){
        cout << e << endl;
    }else cout << -1 << endl;
    // deb(ok(1));
    
}
