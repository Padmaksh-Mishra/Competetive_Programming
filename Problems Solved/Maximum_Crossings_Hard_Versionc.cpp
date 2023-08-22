# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

// shortcuts
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

//namespaces
using namespace __gnu_pbds;
using namespace std;

//templates
template<typename T>
using ordered_set= tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<typename T>
using ordered_multiset = tree<T,null_type,less_equal<T>,rb_tree_tag, tree_order_statistics_node_update>; //less_equal=ms can have duplicates
//order_of_key (K): Number of items strictly smaller than K.
//find_by_order(k): Kth element in a Set (counting from zero).

//Usefull constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

//for fileIO judges
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
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	vll v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	ll crossings = 0;
	ordered_multiset<ll> ms;
	for(int i=0;i<n;++i){

		crossings+=ms.size()-ms.order_of_key(v[i]);
		ms.insert(v[i]);
	}	
	cout << crossings << endl;
}