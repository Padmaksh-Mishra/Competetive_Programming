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
    ll n; cin >> n;
    ll aw=0,ab=0,bw=0,bb=0;
    aw++;
    n--;
    ll x = 1;
    ll i = 2;
    while(n>0){
    	ll b=0,w=0;
	    for(int j=0;j<i+i+1;++j){
			b+=(j%2==0);
			w+=(j%2);
	    }	
    	if(b+w>n) break;
    	if(x){
    		bb+=b;
    		bw+=w;
    	}else{
    		swap(b,w);
    		ab+=b;
    		aw+=w;
    	}
    	i+=2;
    	n-=(b+w);
    	x^=1;
    }
    ll b=0,w=0;
    for(int i=0;i<n;++i){
		b+=(i%2==0);
		w+=(i%2);
    }	
    if(x){
    	bb+=b;
    	bw+=w;
    }else{
    	swap(b,w);
    	ab+=b;
    	aw+=w;
    }
    cout << aw << " " << ab << " " << bw << " " << bb << endl;
}
