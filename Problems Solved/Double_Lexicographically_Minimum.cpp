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
    string s; cin >> s;
    ll n = siz(s);
    vll hsh(26,0);
    vector<char> ans(n,'?');
    for(int i=0;i<n;++i){
        hsh[s[i]-'a']++;
    }
    ll place = 0;
    ll i=0;
    for(i=0;i<26;++i){
        while(hsh[i]>1){
            ans[place++] = ('a'+i);
            ans[n-place] = ('a'+i);
            hsh[i]-=2;
        }
        if(hsh[i]%2){
            break;
        }
    }
    if(i==26){
        for(auto val : ans){
            cout << val;
        }
        cout << endl;
        return;
    }
    ll nz = 0,sec=0;
    for(int j=i;j<26;++j){
        nz+=(hsh[j]>0);
        if(hsh[j]>0) sec = j;
    }
    //more than two symbols
    // deb(nz);
    if(nz!=2){
        ans[n-place-1] = (i+'a');
        for(int j=i+1;j<26;++j){
            while(hsh[j]--){
                ans[place++] = ('a'+j);
            }
        }
    }else{
        ll j = place;
        for(;j<(n/2);++j){
            ans[j] = ('a'+sec);
        }
        ans[j++] = ('a'+i);

        for(;j<(n-place);++j){
            ans[j] = ('a'+sec);
        }
    }
    for(auto val : ans){
        cout << val;
    }
    cout << endl;
}
