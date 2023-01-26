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
	ll u,r,d,l; cin >> u >> r >> d >> l;
	if(u>n||r>n||d>n||l>n){
		cout << "NO" << endl;
		return;
	}
	if(n==2){
		if((l==2||r==2)&&(u<1||d<1)){
			cout << "NO" << endl;
			return;
		}
	}	    
	if(l+r<(u+d-2*n+4)){
		cout << "NO" << endl;
		return;
	}
	if(u+d<(l+r-2*n+4)){
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;
}
