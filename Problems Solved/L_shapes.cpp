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
    vector<string> v(n);
    for(int i=0;i<n;++i){
    	cin >> v[i];
    }
    vector<vll> vis(n,vll(m,0));
    vector<pll> moves = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,-1},{-1,1}};
    function<void(ll,ll)> dfs = [&](ll x,ll y){
    	if(x<0||y<0||x>n-1||y>m-1) return;
    	if(v[x][y]!='*') return;
    	if(vis[x][y]) return;
    	vis[x][y] = 1;
    	for(auto move : moves){
    		dfs(x+move.f,y+move.s);
    	}
    };
    ll cnt = 0,shaded = 0;
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		shaded+=(v[i][j]=='*');
    		if(!vis[i][j]&&v[i][j]=='*'){
    			ll shx = 0,shy=0;
    			if(i>0) shx+=(v[i-1][j]=='*');
    			if(i<n-1) shx+=(v[i+1][j]=='*');
    			if(j>0) shy+=(v[i][j-1]=='*');
    			if(j<m-1) shy+=(v[i][j+1]=='*');
    			if(shx==1&&shy==1){
    				dfs(i,j);
    				cnt++;
    			}
    		}
    	}
    }
    // deb(cnt);
    // deb(shaded);
    if(cnt*3==shaded) YES;
    else NO;
}
