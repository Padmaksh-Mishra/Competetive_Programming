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
    ll l,p; cin >> l >> p;
    set<ll> lines;
    for(int i=0;i<l;++i){
        ll t; cin >> t;
        lines.insert(t);
    }
    // for(auto val : lines) cout << val << " ";
    // cout << endl;
    while(p--){
    	ll a,b,c; cin >> a >> b >> c;
    	ll fac = ((a*c)*4);
    	if(a<0){
    		ll ko = *lines.begin();
    		ll kl = *prev(lines.end());
    		ll vo = (b-ko)*(b-ko);
    		ll vl = (b-kl)*(b-kl);
    		if(vo>fac){
    			YES;
    			cout << ko << endl;
    		}else if(vl>fac){
    			YES;
    			cout << kl << endl;
    		}else NO;
    	}else{
            ll s,bg,vl,vo;
            bool ff=false,ss=false;
    		auto it = lines.lower_bound(b);
            if(it!=lines.begin()) s = *prev(it),ff=true;
            if(it!=lines.end()) bg = *it,ss=true;
    		vo = (b-s)*(b-s);
    		vl = (b-bg)*(b-bg);
    		if(ff&&vo<fac){
    			YES;
    			cout << s << endl;
    		}else if(ss&&vl<fac){
    			YES;
    			cout << bg << endl;
    		}else NO;
    	}
    }
    cout << endl;
}
