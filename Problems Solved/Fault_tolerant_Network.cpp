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
	vll a(n),b(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}	    
	for(int i=0;i<n;++i){
		cin >> b[i];
	}
	ll bfa1,bfan,bfb1,bfbn;
	bfbn=bfb1=bfan=bfa1=INF;
	for(int j=0;j<n;++j){
		bfa1 = min(abs(a[0]-b[j]),bfa1);
	}
	for(int j=0;j<n;++j){
		bfan = min(abs(a[n-1]-b[j]),bfan);
	}
	for(int j=0;j<n;++j){
		bfb1 = min(abs(a[j]-b[0]),bfb1);
	}
	for(int j=0;j<n;++j){
		bfbn = min(abs(a[j]-b[n-1]),bfbn);
	}

	ll ans = min({abs(a[0]-b[0])+abs(a[n-1]-b[n-1]),
					abs(a[0]-b[n-1])+abs(a[n-1]-b[0]),
					abs(a[0]-b[0])+bfan+bfbn,
					abs(a[n-1]-b[n-1])+bfa1+bfb1,
					abs(a[0]-b[n-1])+bfan+bfb1,
					abs(a[n-1]-b[0])+bfa1+bfbn,
					bfa1+bfan+bfb1+bfbn});

	cout << ans << endl;
}
