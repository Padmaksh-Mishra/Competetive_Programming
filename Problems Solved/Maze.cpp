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
    // cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

ll n,m,k; 
vector<string> s(501);
vector<vll> vis(501,vll(501));
vector<pll> moves = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(ll x,ll y,ll mxx){
	ll visited = 0;
	queue<pll> q;
	q.push(make_pair(x,y));
	while(!q.empty()&&visited+k<mxx){
		pll t = q.front();
		q.pop();
		if(vis[t.f][t.s]) continue;
		vis[t.f][t.s] = 1;
		visited++;
		for(auto move : moves){
			ll nx = t.f + move.f;
			ll ny = t.s + move.s;
			if(nx>n-1||nx<0||ny>m-1||ny<0) continue;
			if(s[nx][ny]=='#') continue;
			q.push(make_pair(nx,ny));
		}
	}
}

void solve(){
    cin >> n >> m >> k;
    for(int i=0;i<n;++i){
    	cin >> s[i];
    }
    pll go = {-1,-1};
    ll mxx = 0;
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(s[i][j]=='.'){
    			go = make_pair(i,j);
    			mxx++;
    		}
    	}
    }
    bfs(go.f,go.s,mxx);
    for(int i=0;i<n;++i){
    	for(int j=0;j<m;++j){
    		if(vis[i][j]==0){
    			if(s[i][j]=='.') s[i][j] = 'X';
    		}
    		cout << s[i][j];
    	}
    	cout << endl;
    }
}
