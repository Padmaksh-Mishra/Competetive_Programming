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

class DSU{
private:
	vector<int> par;
	vector<int> size;
public:
	DSU(int n){
		par.resize(n+1);
		size.resize(n+1);
		for(int i=1;i<n+1;++i){
			par[i] = i;
			size[i] = 1;
		}
	}
	bool unite(int a,int b){
		a = get(a);
		b = get(b);
		if(a==b) return false;
		if(size[a]>size[b]) swap(a,b);
		par[a] = b;
		size[b]+=size[a];
		return true;
	}
	bool same_set(int a,int b){
		a = get(a);
		b = get(b);
		return (a==b);
	}
	int get(int x){
		if(par[x]==x) return x;
		while(par[x]!=x){
			return par[x] = get(par[x]);
		}
		return 0;
	}
};
struct hole{
	int a,b,w;
};
void solve(){
    int n,m; cin >> n >> m;
    vector<int> cows(n+1);
    for(int i=1;i<n+1;++i) cin >> cows[i];
    vector<struct hole> worms(m);
	int mw = 0;
	for(int i=0;i<m;++i){
		cin >> worms[i].a >> worms[i].b >> worms[i].w;
		mw = max(mw,worms[i].w);
	}
	int s = 0,e = mw+1;
	function<bool(int)> ok = [&](int mid){
		DSU tmp(n);
		for(auto worm : worms){
			if(worm.w>mid-1){
				tmp.unite(worm.a,worm.b);
			}
		}
		bool fine = true;
		for(int i=1;i<n+1;++i){
			if(!tmp.same_set(i,cows[i])){
				fine = false;
				break;
			}
		}
		return fine;
	};
	bool no_need = true;
	for(int i=1;i<n+1;++i){
		if(cows[i]!=i){
			no_need = false;
			break;
		}
	}
	// deb(mw);
	if(no_need){
		cout << -1 << endl;
		return;
	}
	while(e-s>1){
		int mid = s + (e-s)/2;
		bool fine = ok(mid);
		if(fine) s = mid;
		else e = mid-1;
	}
	if(ok(e)) cout << e << endl;
	else cout << s << endl;
}
