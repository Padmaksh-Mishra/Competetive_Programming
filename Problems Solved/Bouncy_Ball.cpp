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
    ll sx,sy,ex,ey; cin >> sx >> sy >> ex >> ey;
    string t; cin >> t;
    ll drxn = ((t[0]=='D')<<1)+(t[1]=='R');
    vector<vector<vll>> states(n+1,vector<vll>(m+1,vll(4)));
    states[sx][sy][drxn]=1;
    ll ans = 0;
    while(true){
    	if(sx==ex&&sy==ey){
			cout << ans << endl;
			return;
		} 
    	bool bounce = false;
    	if(drxn==0){	//UL
    		if(sx==1){ 
    			drxn|=2;
    			bounce=true;
    		}
			if(sy==1){ 
				drxn|=1;
				bounce=true;
			}
    	}else if(drxn==1){	//UR
    		if(sx==1){ 
    			drxn|=2;
    			bounce=true;
    		}
			if(sy==m){ 
				drxn^=1;
				bounce=true;
			}
    	}else if(drxn==2){	//DL
    		if(sx==n) {
    			drxn^=2;
    			bounce=true;
    		}
			if(sy==1) {
				drxn|=1;
				bounce=true;
			}
    	}else{		//DR
    		if(sx==n) {
    			drxn^=2;
    			bounce=true;
    		}
			if(sy==m) {
				drxn^=1;
				bounce=true;
			}
    	}
    	if(bounce) ans++;
    	if(drxn==0){	//UL
			sx--;
			sy--;
    	}else if(drxn==1){	//UR
			sx--;
			sy++;
    	}else if(drxn==2){	//DL
			sx++;
			sy--;
    	}else{		//RD
			sx++;
			sy++;
    	}
    	if(states[sx][sy][drxn]==1){
    		cout << -1 << endl;
    		return;
    	}else states[sx][sy][drxn]=1;
		   	
    }
}
