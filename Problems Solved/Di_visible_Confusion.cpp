# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 1e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();
vll lcms(22);
void lcmf(){
	lcms[1] = 1;
	for(ll i=2;i<=21;++i){
		lcms[i] = (i*lcms[i-1])/__gcd(i,lcms[i-1]);
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	lcmf();
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
	vll arr(n);
	for(int i=0;i<n;++i) cin >> arr[i];
	for(int i=0;i<n;++i){
		bool ok = false;
		for(int j=2;j<=i+2;++j){
			if(arr[i]%j!=0){ 
				ok = true;
				break;
			}
		}
		if(!ok){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	return;

}