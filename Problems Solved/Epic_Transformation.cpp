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
	map<ll,ll> m;
	multiset<ll> ms;
	for(int i=0;i<n;++i){
		ll tm; cin >> tm;
		m[tm]++;
	}	
	for(auto val : m){
		ms.insert(val.s);
	}    
	while(siz(ms)>1){
		auto it1 = prev(ms.end());
		ms.erase(it1);
		auto it2 = prev(ms.end());
		ms.erase(it2);
		ll val1 = *it1;
		ll val2 = *it2;
		val2--,val1--;
		if(val1) ms.insert(val1);
		if(val2) ms.insert(val2);
	}
	if(siz(ms)){
		cout << *ms.begin() << endl;
	}else cout << 0 << endl;
}
