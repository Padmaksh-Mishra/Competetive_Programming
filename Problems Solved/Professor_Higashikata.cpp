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

void solve(){
    int n,m,q; cin >> n >> m >> q;
    string s; cin >> s;
    set<int> nusd;
    for(int i=0;i<n;++i){
    	nusd.insert(i);
    }
    vector<int> odr;
    for(int i=0;i<m;++i){
    	int a,b; cin >> a >> b;
    	a--,b--;
    	auto it = nusd.lower_bound(a);
    	auto beg = it;
    	for(;*it<b+1&&it!=nusd.end();++it){
    		odr.emplace_back(*it);
    	}
    	nusd.erase(beg,it);
    }
    map<int,int> mpp;
    for(int i=0;i<siz(odr);++i) mpp[odr[i]] = i;
    // for(auto val : odr) cout << val << ' ';
    // cout << endl;
	int ans = 0;
	int cnt = 0;
	for(int i=0;i<n;++i) if(s[i]=='1') cnt++;
	for(int i=0;i<min(cnt,siz(odr));++i){
		if(s[odr[i]]=='0') ans++;
	}
	while(q--){
		int i; cin >> i;i--;
		if(nusd.find(i)==nusd.end()&&mpp[i]<cnt){
			if(s[i]=='0'){
				ans--;
			}else ans++;
		}
		if(s[i]=='0'){
			s[i]='1';
			cnt++;
			if(cnt<odr.size()+1&&cnt>0&&s[odr[cnt-1]]=='0') ans++;
		}else{
			s[i]='0';
			if(cnt<odr.size()+1&&cnt>0&&s[odr[cnt-1]]=='0') ans--;
			cnt--;
		}
		cout << ans << endl;
	}
}
