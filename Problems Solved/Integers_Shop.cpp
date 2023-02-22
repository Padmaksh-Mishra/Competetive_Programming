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
const int N = 2e5 + 1;  //it's better than me <FORNOW> :) 

//For fileIO
void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
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
	map<pll,ll> m;
	ll lol = INF,llv = INF,hr = -INF,hrv = INF;
	ll lenc = INF,len = -INF;
	for(int i=0;i<n;++i){
		ll l,r,c; cin >> l >> r >> c;
		if(l<lol){
			lol = l;
			llv = c;
		}else if(l==lol){
			llv = min(llv,c);
		}
		if(r>hr){
			hr = r;
			hrv = c;
		}else if(r==hr){
			hrv = min(hrv,c);
		}
		ll ans = llv+hrv;

		// O(nlogn)
		// if(lol==l&&hr==r) ans=min(ans,c);
		// if(m[{lol,hr}]!=0) m[{lol,hr}] = min(m[{lol,hr}],ans);
		// else m[{lol,hr}] = ans;
		// cout << m[{lol,hr}] << endl;
		
		//OPTIMIZATION--> O(n)
		if(len<(r-l+1)){
			len = r-l+1;
			lenc = c;	
		}else if(len==r-l+1){
			lenc = min(lenc,c);
		}
		if(len==hr-lol+1) ans = min(lenc,ans);
		cout << ans << endl;
	}	    
}
