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
    function<ll(ll,ll)> qurry = [](ll a,ll b){
    	ll tmp;
    	cout << "? " << a << " " << b << endl;
    	cout.flush();
    	cin >> tmp;
    	return tmp;
    };
    
    ll d1 = qurry(1,1);
    ll d2 = qurry(n,m);
    ll x1 = d1+1;
    ll y1 = d1+1;
    ll x2 = n-d2;
    ll y2 = m-d2;
    if(x1<1) x1=1;
    if(y1<1) y1=1;
    if(x1>n) x1=n;
    if(y1>m) y1=m;
    if(x2<1) x2=1;
    if(y2<1) y2=1;
    if(x2>n) x2=n;
    if(y2>m) y2=m;
    
    pll ans = {-1,-1};
    // deb(x1);
    // deb(x2);
    if(x1==x2){
        ans.f = x1;
        ans.s = qurry(x1,1)+1;
    }else if(y1==y2){
        ans.s = y1;
        ans.f = qurry(1,y1) + 1;
    }else{
        ll dd = qurry(x1,y2);
        if(dd==0) ans.f=x1,ans.s=y2;
        else ans.f=x2,ans.s=y2;
    }
    // ll d3 = qurry(x1,y2);
    // if(d3==0){
    //     ans.f = x1;
    //     ans.s = y2;
    // }else{
    //     ans.f = x2;
    //     ans.s = y1;
    // }
    
    cout << "! " << ans.f << " " << ans.s << endl;
    cout.flush(); 
}
