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
    ll n; cin >> n;
    ll m = (2*n)-2;
	vector<string> v;
	vll hsh(26);
	for(int i=0;i<m;++i){
		string s; cin >> s;
		for(int i=0;i<siz(s);++i){
			hsh[s[i]-'a'] = 1;
		}
		if(siz(s)==n-1) v.emplace_back(s);
	}   
	string o = v[0];
	string s = v[1];
	// cout << o << " " << s << endl;
	string t1 = o[0]+s;
	string t2 = s[0]+o;
	string t3 = s+o[n-1];
	string t4 = o+s[n-1];
	// cout << t1 << " " << t2 << endl;
	bool ok1 = true,ok2 = true,ok3=true,ok4=true;
	// for(int i=0;i<)
	for(int i=0;i<n/2;++i){
		if(t1[i]!=t1[n-i-1]){
			ok1 = false;
			break;
		}
	}
	for(int i=0;i<n/2;++i){
		if(t2[i]!=t2[n-i-1]){
			ok2 = false;
			break;
		}
	}
	for(int i=0;i<n/2;++i){
		if(t3[i]!=t3[n-i-1]){
			ok3 = false;
			break;
		}
	}
	for(int i=0;i<n/2;++i){
		if(t4[i]!=t4[n-i-1]){
			ok4 = false;
			break;
		}
	}
	for(int i=0;i<26;++i){
		if(hsh[i]){
			bool fine = 0;
			for(int j=0;j<n;++j){
				if(t1[j]==char('a'+i)){
					fine = 1;
					break;
				}
			}
			if(!fine){
				ok1 = false;
			}
		}
	}
	for(int i=0;i<26;++i){
		if(hsh[i]){
			bool fine = 0;
			for(int j=0;j<n;++j){
				if(t2[j]==char('a'+i)){
					fine = 1;
					break;
				}
			}
			if(!fine){
				ok2 = false;
			}
		}
	}
	for(int i=0;i<26;++i){
		if(hsh[i]){
			bool fine = 0;
			for(int j=0;j<n;++j){
				if(t3[j]==char('a'+i)){
					fine = 1;
					break;
				}
			}
			if(!fine){
				ok3 = false;
			}
		}
	}
	for(int i=0;i<26;++i){
		if(hsh[i]){
			bool fine = 0;
			for(int j=0;j<n;++j){
				if(t4[j]==char('a'+i)){
					fine = 1;
					break;
				}
			}
			if(!fine){
				ok4 = false;
			}
		}
	}
	if(ok1||ok2||ok3||ok4) YES;
	else NO;
}
