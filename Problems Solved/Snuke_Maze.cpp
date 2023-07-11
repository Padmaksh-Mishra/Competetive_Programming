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
    ll h,w; cin >> h >> w;
    vector<string> mat(h);
    for(int i=0;i<h;++i) cin >> mat[i];
    vector<vector<int>> vis(h,vector<int>(w));
	vector<pll> moves = {{1,0},{-1,0},{0,1},{0,-1}};
	map<char,int> mpp;
	mpp['s']=0;
	mpp['n']=1;
	mpp['u']=2;
	mpp['k']=3;
	mpp['e']=4;
    function<void(int,int,int)> dfs = [&](int x,int y,int c){
    	if(vis[x][y]) return;
    	vis[x][y] = 1;
    	// deb(c);
    	for(auto move : moves){
    		int nx = x+move.f;
    		int ny = y+move.s;
    		if(nx>h-1||ny>w-1||nx<0||ny<0) continue;
    		if(vis[nx][ny]) continue;
    		// deb(mpp[mat[nx][ny]]);
    		if(mpp[mat[nx][ny]]==(c+1)%5) dfs(nx,ny,(c+1)%5);
    	}
    };
    if(mat[0][0]!='s'){
    	NO;
    	return;
    }
    dfs(0,0,0);
    
    if(vis[h-1][w-1]){
    	YES;
    }else NO;
    
}
