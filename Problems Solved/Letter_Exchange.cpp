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
struct anstype{
	ll a,b;
	char x,y;
};
void solve(){
    ll n; cin >> n;
    vll wi,wn,iw,nw,in,ni;
    for(int idx=0;idx<n;++idx){
    	string s; cin >> s;
    	ll w=0,i=0,n=0;
        // cout << s << endl;
    	for(int x=0;x<3;++x){
            // deb(s[x]);
    		w+=(s[x]=='w');
    		i+=(s[x]=='i');
    		n+=(s[x]=='n');
    	}
        // cout << w << " " << i << " " << n << endl;
    	if(w==3){
    		wi.emplace_back(idx);
    		wn.emplace_back(idx);
    	}else if(i==3){
    		iw.emplace_back(idx);
    		in.emplace_back(idx);
    	}else if(n==3){
    		nw.emplace_back(idx);
    		ni.emplace_back(idx);
    	}else if(w==2){
    		if(i==1) wn.emplace_back(idx);
    		else wi.emplace_back(idx);
    	}else if(i==2){
    		if(n==1) iw.emplace_back(idx);
    		else in.emplace_back(idx);
    	}else if(n==2){
    		if(w==1) ni.emplace_back(idx);
    		else nw.emplace_back(idx);
    	}
    }
    // cout << siz(nw) << " " << siz(in) << " " << siz(wi) << endl;
    vector<anstype> ans;
    // seeing cycle of length 2
    // deb(siz(wi));
    auto cyt = [&ans](vll &a,char x,vll &b,char y){
    	// deb(siz(a));
    	while(min(siz(a),siz(b))){
    		ll f = a.back();
    		a.pop_back();
    		ll s = b.back();
    		b.pop_back();
    		anstype tmp;
    		tmp.a = f+1;
    		tmp.b = s+1;
    		tmp.x = x;
    		tmp.y = y;
    		ans.emplace_back(tmp);
    	}
    };
    cyt(wi,'w',iw,'i');
    cyt(wn,'w',nw,'n');
    cyt(ni,'n',in,'i');


    //cycle length 3
    auto cyr = [&ans](vll &a,char aa,vll &b,char bb,vll &c,char cc){
        while(min({siz(a),siz(b),siz(c)})){
            // cout << 'H' << endl;
            ll an = a.back();
            a.pop_back();
            ll bn = b.back();
            b.pop_back();
            ll cn = c.back();
            c.pop_back();

            anstype tmp;
            tmp.a = an+1;
            tmp.b = bn+1;
            tmp.x = aa;
            tmp.y = bb;
            ans.emplace_back(tmp);
            // anstype tmp2;
            tmp.a = an+1;
            tmp.b = cn+1;
            tmp.x = bb;
            tmp.y = cc;
            ans.emplace_back(tmp);
        }
    };
    // cout << siz(nw) << " " << siz(in) << " " << siz(wi) << endl;
    cyr(wi,'w',nw,'n',in,'i');                                                   
    // cyr(nw,'n',in,'i',wi,'w');
    // cyr(in,'i',wi,'w',nw,'n');

    cyr(iw,'i',ni,'n',wn,'w');
    // cyr(wn,'w',ni,'n',iw,'i');
    // cyr(ni,'n',iw,'i',wn,'w');

    cout << siz(ans) << endl;
    for(auto val : ans){
    	cout << val.a << " " << val.x << ' ' << val.b << ' ' << val.y << endl;
    }
}
