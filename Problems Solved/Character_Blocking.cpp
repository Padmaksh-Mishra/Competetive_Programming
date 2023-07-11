# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll int
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


void solve();

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr); 
    //setIO("sublime");        
    ll TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
        // cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

void solve(){
    string a,b; cin >> a >> b;
    ll t,q; cin >> t >> q;
    ll n = siz(a);
    ll cnt = 0;

    for(int i=0;i<n;++i){
        if(a[i]!=b[i]) cnt++;
    }
    vector<int> cr(n);
    ll time = 0;
    queue<pll> s;
    while(q--){
        ll ty; cin >> ty;
        while(!s.empty()&&s.front().f==time){
            ll ps = s.front().s;
            if(a[ps]!=b[ps]) cnt++;
            s.pop();
        }
        if(ty==1){
            ll pos; cin >> pos;
            pos--;
            s.push(make_pair(t+time,pos));
            if(a[pos]!=b[pos]) cnt--;
        }else if(ty==2){
            ll x,y,z,zz; cin >> x >> y >> z >> zz;
            if(a[y-1]!=b[y-1]) cnt--;
            if(a[zz-1]!=b[zz-1]) cnt--;

            if(x==1&&z==1) swap(a[y-1],a[zz-1]);
            else if(x==1&&z==2) swap(a[y-1],b[zz-1]);
            else if(x==2&&z==1) swap(b[y-1],a[zz-1]);
            else swap(b[y-1],b[zz-1]);

            if(a[y-1]!=b[y-1]) cnt++;
            if(a[zz-1]!=b[zz-1]) cnt++;
        }else{
            if(cnt==0) YES;
            else NO;
        }
        // deb(cnt);

        time++;
    }
    cr.clear();
}