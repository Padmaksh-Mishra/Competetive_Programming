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

const ll MOD = 998244353;
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
    setIO("sublime");    //Does not work with Google     
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
	vll o,e;
	ll tmp,ones=0;
	for(int i=0;i<n;++i){
		cin >> tmp;
		if(tmp==1) ones++;
		else if(tmp&1) o.emplace_back(tmp);
		else e.emplace_back(tmp);
	}	    
	sort(all(e));
	ll p = 1;
	for(auto even : e){
		if(ones){
			p = (p*(even+1))%MOD;
			ones--;
		}else p = (p*even)%MOD;
	}
	for(auto odd : o){
		p = (p*odd)%MOD;
	}
	cout << (p%MOD) << endl;
}
