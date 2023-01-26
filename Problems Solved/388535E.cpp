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
const int ME = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();
vll xors(ME);

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google
    ll xord = 0;     
    for(int i=0;i<ME;++i){
    	xord^=i;
    	xors[i] = xord;
    }
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
	ll l,r; cin >> l >> r;
	ll xora = 0;
	for(int i=0;i<r+1;++i){
		ll tmp; cin >> tmp;
		xora^=tmp;
	}
	ll ans = 0;
	if(r==0){
		cout << 0 << endl;
		return;
	}
	if(r%2==0){
		ans = xora^xors[r];
	}else{
		ans = (xora^xors[r-1]);
	}
	cout << ans << endl;
}
