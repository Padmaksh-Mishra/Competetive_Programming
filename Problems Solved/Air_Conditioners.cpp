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
	ll n,k; cin >> n >> k;
	vll t(n,INF);
	vll tmp(k),tmpp(k);
	for(int i=0;i<k;++i){
		cin >> tmp[i];
	}
	for(int i=0;i<k;++i){
		cin >> tmpp[i];
	}
	vector<pll> a;
	for(int i=0;i<k;++i){
		a.emplace_back(make_pair(tmp[i]-1,tmpp[i]));
	}
	sort(all(a),[](pll x,pll y)->bool{
		if(x.s<y.s){
			return true;
		}
		return false;
	});
	for(auto val : a){
		t[val.f] = val.s;
	}
	for(auto val : a){
		ll p = val.f;
		ll x=1;
		while(x+p<n){
			ll th = val.s+x;
			if(th>=t[p+x]){
				break;
			}
			t[p+x] = th;
			x++;
		}
		x = 1;
		while(x<p+1){
			ll th = val.s+x;
			if(th>=t[p-x]){
				break;
			}
			t[p-x] = th;
			x++;
		}
	}
	for(int i=0;i<n;++i){
		cout << t[i] << " ";
	}
	cout << endl;
}
