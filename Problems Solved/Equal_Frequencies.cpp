# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define vpll vector<pll>
# define all(x) (x).begin(), (x).end()

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
const int N = 2e5 + 1;   

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

// Doing something good 

void solve(){
    ll n; cin >> n;
    string s; cin >> s;
    vll times(26,0);
    for(int i=0;i<n;++i){
    	times[s[i]-'a']++;
    }
    vll facs;
    facs.emplace_back(1);
    for(int i=2;i*i<n+1;++i){
    	if(n%i==0) facs.emplace_back(i);
    }
    facs.emplace_back(n);
    pll cost = {INF,INF};
    for(auto kal : facs){
    	ll tmp = 0;
    	vector<pll> tmpv;
    	for(int i=0;i<26;++i){
    		tmpv.emplace_back(make_pair(abs(times[i]-kal),times[i]));
    	}
    	sort(all(tmpv),[](pll a,pll b)->bool{
    		if(a.f=b.f){
    			return a.s>b.s;
    		}
    		return a.f<b.f;
    	});
    	ll tc = 0;
    	for(auto val : tmpv){
    		ll cst = min(n-tmp,val.f);
    		tc+=cst;
    		tmp+=kal+cst;
    		tmp = min(n,tmp);
    		if(tmp==n){
    			if(cost.f>tc){
    				cost.f = tc;
    				cost.s = kal;
    			}
    			break;
    		}
    	}
    }
    cout << cost.f << endl;
    // deb(cost.s);
    set<char> used;
    vll ch(26);
    vector<pair<ll,char>> occs;
    for(int i=0;i<n;++i){
        ch[s[i]-'a']++;
    }
    for(int i=0;i<26;++i){
        if(ch[i]){
            occs.emplace_back(make_pair(abs(cost.s-ch[i]),i+'a'));
        }
    }
    sort(all(occs));
    set<char> good;
    ll g = 0;
    while(g*cost.s<n){
        good.insert(occs[g].s);
        g++;
    }
    vector<char> need,extra;
    for(auto val : good){
        if(ch[val-'a']<cost.s){
            for(int i=0;i<cost.s-ch[val-'a'];++i){
                need.emplace_back(val);
            }
        }else if(ch[val-'a']>cost.s){
            for(int i=0;i<ch[val-'a']-cost.s;++i){
                extra.emplace_back(val);
            }
        }
    }
    ll e = 0,ne = 0;
    while(siz(need)){
        char tmp = need.back();
        deb(s.find(extra.back()));
        extra.pop_back();
        need.pop_back();
    }
}
