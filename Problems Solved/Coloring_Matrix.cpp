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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    ll n; cin >> n;
    vector<vll> ao(n+1,vll(n+1)),at(n+1,vll(n+1)),ar(n+1,vll(n+1)),af(n+1,vll(n+1)),b(n+1,vll(n+1));
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		ll t; cin >> t;
    		ao[i][j]=at[n+1-j][i]=ar[n+1-i][n+1-j]=af[j][n+1-i]=t;
    	}
    }
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		cin >> b[i][j];
    	}
    }
    ll o,t,r,f;
    o=t=r=f=1;
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		if(ao[i][j]==0) continue;
    		if(b[i][j]!=ao[i][j]){
    			o=0;
    			break;	
    		}		
    	}
    	if(o==0) break;
    }
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		if(at[i][j]==0) continue;
    		if(b[i][j]!=at[i][j]){
    			t=0;
    			break;	
    		}
    	}
    	if(t==0) break;
    }
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		// cout << ar[i][j] <<  " "; 
    		if(ar[i][j]==0) continue;
    		if(b[i][j]!=ar[i][j]){
    			r=0;
    			break;	
    		}
    	}
    	// cout << endl;
    	if(r==0) break;
    }
    for(int i=1;i<n+1;++i){
    	for(int j=1;j<n+1;++j){
    		if(af[i][j]==0) continue;
    		if(b[i][j]!=af[i][j]){
    			f=0;
    			break;	
    		}
    	}
    	if(f==0) break;
    }
    // cout << o << " " << t << " " << r << " " << f << endl;
    if(o==t&&t==r&&r==f&&f==0) NO;
    else YES;
    return;
}
