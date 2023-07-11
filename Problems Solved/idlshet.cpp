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
    ll ax,ay; cin >> ax >> ay;
    vector<string> a(ax);
    ll bsc = 0;
    for(int i=0;i<ax;++i) cin >> a[i];
    ll bx,by; cin >> bx >> by;
    vector<string> b(bx);
    for(int i=0;i<bx;++i) cin >> b[i];
    ll xx,xy; cin >> xx >> xy;
    vector<string> x(xx);
    for(int i=0;i<xx;++i) cin >> x[i];


    for(int i=0;i<ax;++i){
    	for(int j=0;j<ay;++j){
    		bsc+=(a[i][j]=='#');
    	}
    }
    ll t = 0;
    for(int i=0;i<bx;++i){
    	for(int j=0;j<by;++j){
    		t+=(b[i][j]=='#');
    	}
    }
    int bscc = bsc + t;

    bsc = max(t,bsc);
    t = 0;
    for(int i=0;i<xx;++i){
    	for(int j=0;j<xy;++j){
    		t+=(x[i][j]=='#');
    	}
    }
    if(bsc>t||bscc<t){ 
    	NO;
    	return;
    }
    vector<vector<char>> mp(55,vector<char>(55));
	function<void()> paint = [&](){
		for(int i=0;i<55;++i) fill(all(mp[i]),'.');
		for(int i=0;i<ax;++i){
			for(int j=0;j<ay;++j){
				mp[i+25][j+25] = a[i][j];

			}
		}
	};
	for(int i=0;i<50;++i){
		for(int j=0;j<50;++j){
			paint();
			for(int ii=0;ii<bx;++ii){
				for(int jj=0;jj<by;++jj){
					if(i+ii>50||j+jj>50) continue;
					if(mp[i+ii][j+jj]=='.') mp[i+ii][j+jj] = b[ii][jj];
				}
			}
			for(int t=0;t<50;++t){
				bool ans = true;
				for(int k=0;k<50;++k){
					for(int w=0;w<xx;++w){
						for(int v=0;v<xy;++v){
							if(w+t>50||v+t>50) continue;
							if(x[w][v]!=mp[t+w][k+v]){
								ans = false;
								break;
							}
						}
						if(ans){
							YES;
							return;
						}
					}
				}
			}
		}
	}
	NO;
}
