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
    ll n,m; cin >> n >> m;
    vll prsn(n);
    for(int i=0;i<n;++i) cin >> prsn[i];
    sort(all(prsn),greater<ll>());
	vll seats(m);
	ll o = 0,t=0;
	for(int i=0;i<n;++i){
		if(prsn[i]<0){
			o+=(prsn[i]==-1);
			t+=(prsn[i]==-2);
		}else seats[prsn[i]-1] = 1;
	}
	ll lsf = m-1;
	for(int i=0;i<m;++i){
		if(seats[i]&&o<i){
			lsf = i-1;
			break;
		}
	}
	ll rsf = 0;
	for(int i=m-1;i>-1;--i){
		if(seats[i]&&t+i<m){
			rsf = i+1;
			break;
		}
	}
	if(lsf==m-1){
		if(o>t) t = 0;
		// else r = 0;
	}else if(rsf==0){
		if(t>o) o = 0;
	}
	for(int i=lsf;i>-1&&o>0;--o,--i) seats[i] += 1;
	for(int i=rsf;i<m&&t>0;--t,++i) seats[i] += 1;
	// for(auto s : seats) cout << s << " ";
	// cout << endl;
	cout << min(m,accumulate(all(seats),0ll)) << endl;
}
