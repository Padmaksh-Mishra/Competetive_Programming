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


//Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const ll N = 2e5 + 1;   


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
   int n; cin >> n;
   vll v(n);
   for(int i=0;i<n;++i) cin >> v[i];
    sort(all(v));
    vll ans(n);
    int j=0;
    for(int i=0;i<n;i+=2){
        ans[i] = v[j++];
    }   
    for(int i=1;i<n;i+=2){
        ans[i] = v[j++];
    }
    for(int i=1;i<n-1;++i){
        if((ans[i-1]<ans[i]&&ans[i]>ans[i+1])||(ans[i-1]>ans[i]&&ans[i]<ans[i+1])){
            //fine
        }else{
            cout << -1 << endl;
            return;
        }
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}
