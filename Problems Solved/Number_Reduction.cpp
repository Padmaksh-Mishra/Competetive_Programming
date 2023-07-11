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
    string s; cin >> s;
    ll n = siz(s);
    ll k; cin >> k;
    ll sc = n;
    ll tmp = INF;
    for(int i=0;i<n;++i){
    	if(s[i]=='0'){
    		break;
    	}
    	if(tmp>s[i]-'0') tmp = s[i]-'0',sc = i;
    }
    deb(sc);
    if(sc<k){
    	s = s.substr(sc);
    }
    vll idx[10];
    for(int i=0;i<n;++i){
    	idx[s[i]-'0'].emplace_back(i);
    }
    tmp = 9;
	while(true){
		for(auto val : idx[tmp]){
			// deb(val);
			if(val==sc){
				for(auto val : idx[0]){
					s[val] = 'x';
					k--;
					if(k==0) break;
				}
				if(k==0) break;
			}else{
				s[val] = 'x';
				k--;
				if(k==0) break;
			}
		}
		if(k==0) break;
		tmp--;
	}
	for(char c : s){
		if(c!='x'){
			cout << c;
		}
	}
	cout << endl;
}
