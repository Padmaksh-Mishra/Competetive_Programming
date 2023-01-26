# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

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
	multiset<ll,greater<ll>> s;
	vll peop(n);
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		auto it = s.lower_bound(tmp);
		auto it2 = s.lower_bound(tmp+1);
		ll noeletm = distance(it2,it);
		if(noeletm==0) s.insert(tmp);
		peop[i] = noeletm;
	}	    
	ll msum = 0,sum = 0;
	for(auto val : peop){
		if(val>0){
			sum+=val;
		}else msum = max(msum,sum);
	}
	msum = max(sum,msum);
	cout << msum << endl;
}
