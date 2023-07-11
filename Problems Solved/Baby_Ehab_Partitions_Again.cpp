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
    ll n; cin >> n;
    vll a(n);
    ll sum = 0;
    map<ll,ll> m;
    for(int i=0;i<n;++i){
    	cin >> a[i];
    	m[a[i]]=i;
    	sum+=a[i];
    }
    if(sum%2){
    	cout << 0 << endl;
    	return;
    }
    sum>>=1;
    sort(all(a));
    vector<vll> dp(n+1,vll(sum+1));
    dp[0][0]=1;
    for(int i=0;i<n;++i){
    	for(int j=0;j<sum+1;++j){
    		if(i<n) dp[i+1][j] |= dp[i][j];
    		if(i<n&&j+a[i]<sum+1) dp[i+1][j+a[i]] |= dp[i][j];
    	}
    }
    if(dp[n][sum]==0){
    	cout << 0 << endl;
    	return;
    }

    //---------------------------------------------------------------
    // Unintended solution will be hacked

    // function<ll(ll)> napsak = [&a,n](ll idx){
    // 	vll wa;
    // 	ll sum = 0;
    // 	for(int i=0;i<n;++i){
    // 		if(i==idx) continue;
    // 		wa.emplace_back(a[i]);
    // 		sum+=a[i];
    // 	}
    // 	if(sum%2){
    // 		return 0ll;
    // 	}
    // 	sum>>=1;
    // 	// deb(sum);
    // 	ll m = n-1;
    // 	vector<vll> dp(m+1,vll(sum+1));
	//     dp[0][0]=1;
	//     for(int i=0;i<m;++i){
	//     	for(int j=0;j<sum+1;++j){
	//     		if(i<m) dp[i+1][j] |= dp[i][j];
	//     		if(i<m&&j+wa[i]<sum+1) dp[i+1][j+wa[i]] |= dp[i][j];
	//     	}
	//     }
	//     return dp[m][sum];
    // };
    // for(int i=0;i<n;++i){
    // 	if(napsak(i)==0){
    // 		cout << 1 << endl << m[a[i]]+1 << endl;
    // 		return;
    // 	}
    // }
    //------------------------------------------------------------------

    //Right solution
    
    ll mv = 32;
    ll mvi = 0;
    for(int i=0;i<n;++i){
    	ll t=0;
    	ll tmp = a[i];
    	while(true){
    		if((tmp>>t)&1) break;
    		t++;
    	}
    	if(t<mv){
    		mv = t;
    		mvi = m[a[i]];
    	}
    }
    cout << 1 << endl;
    cout << mvi+1 << endl;
}
