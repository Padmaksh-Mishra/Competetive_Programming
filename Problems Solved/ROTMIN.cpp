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
    ll n,p,q; cin >> n >> p >> q;
    string st; cin >> st;
    function<bool(ll)> chk = [&](ll k){
    	ll np = p,nq = q;
    	vector<pll> v;
    	for(int i=0;i<k;++i){
    		pll t = {'a'-st[i]+26,st[i]-'a'};
    		v.emplace_back(t);
    	}
    	sort(all(v));
    	for(auto val : v){
    		if(np>val.f-1){
    			np-=val.f;
    		}else if(nq>val.s-1){
    			nq-=val.s;
    		}else return false;
    	}
    	return true;
    };

    ll s=0,e=n,mid;
    while(e-s>1){
    	mid = s + ((e-s)/2);
    	bool b = chk(mid);
    	if(b){
    		s=mid;
    	}else e=mid-1;
    }
    ll k = (chk(e)?e:s);
    vector<pll> v;
	for(int i=0;i<k;++i){
		pll t = {'a'-st[i]+26,st[i]-'a'};
		v.emplace_back(t);
	}
	sort(all(v));
	for(auto val : v){
		if(p>val.f-1){
			p-=val.f;
		}else if(q>val.s-1){
			q-=val.s;
		}
	}
    for(int i=0;i<k;++i){
    	st[i]='a';
    }
    if(k<n) st[k]-=q;
    for(int i=k+1;i<n;++i){
    	if('a'-st[i]+26<p+1){
    		st[i]='a';
    		p-=('a'-st[i]+26);
    	}
    }
    cout << st << endl;
}
