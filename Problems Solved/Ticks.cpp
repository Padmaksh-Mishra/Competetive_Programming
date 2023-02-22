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
	ll n,m,k; cin >> n >> m >> k;
	vector<string> v(n);
	vector<vll> vis(n,vll(m,0));
	for(int i=0;i<n;++i){
		cin >> v[i];
	}	    
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(v[i][j]=='*'){
				//ls
				ll ls = 0;
				while(true){
					if(v[i-ls][j-ls]=='*'){
						ls++;
					}else break;
					if(i-ls<0||j-ls<0){
						break;
					}
				}
				//rs
				ll rs = 0;
				while(true){
					if(v[i-rs][j+rs]=='*'){
						rs++;
					}else break;
					if(i-rs<0||j+rs>m-1){
						break;
					}
				}
				// cout << ls << " " << rs << endl;
				ll dist = min(ls,rs);
				if(dist>k){
					while(dist>0){
						vis[i-dist+1][j-dist+1]++;
						if(dist) vis[i-dist+1][j+dist-1]++;
						dist--;
					}
				}
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(v[i][j]=='*'&&vis[i][j]<1){
				cout << "NO" << endl;
				return;
			}
		}
	}
	cout << "YES" << endl;
	return;
}
