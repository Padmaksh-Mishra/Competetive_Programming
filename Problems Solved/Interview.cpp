# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

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
        cout.flush();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    vll es(n+1);
    vll ns(n);
    for(int i=0;i<n;++i){
    	cin >> ns[i];
    	es[i+1] = es[i] + ns[i];
    }
    auto query = [](ll s,ll e)->ll{
    	cout << "? " << e-s << " ";
    	for(int i=s+1;i<e+1;++i){
    		cout << i << " ";
    	}
    	cout << endl;
    	ll t; cin >> t;
    	return t;
    };
    ll s=0,e=n,mid;
    while(e-s>0){
    	mid = (e+s)/2;
    	ll tmp = es[mid+1] - es[s];
    	ll act = query(s,mid+1);
    	if(tmp!=act){
    		e = mid;
    	}else{
    		s = mid+1;
    	}
    }
	if(query(s,s+1)!=ns[s]) cout << "! " << s+1 << endl;  
	else if(query(mid,mid+1)!=ns[mid]) cout << "! " << mid+1 << endl;
	else if(query(e,e+1)!=ns[e]) cout << "! " << e+1 << endl;
    else if(query(s-1,s)!=ns[s-1]) cout << "! " << s << endl;  
    else if(query(e+1,e)!=ns[e]) cout << "! " << e+2 << endl; 

}
