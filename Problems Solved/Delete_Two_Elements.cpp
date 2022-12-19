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
	cin.tie(NULL); 
	cout.tie(NULL);
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
	ll n,k=0; cin >> n;
	vll ele(n);
	map<ll,ll> m;
	for(int i=0;i<n;++i) {
		cin >> ele[i];
		k+=ele[i];
	}
	if((2*k)%n!=0){
		cout << 0 << endl;
	}else{
		ll ans = 0;
		ll rs = (2*k)/n;
		set<ll> s(all(ele));
		for(int i=0;i<n;++i){
			m[ele[i]]++;
			ans+=m[rs-ele[i]];
			if(rs-ele[i]==ele[i]) ans--;
		}
		cout << ans << endl;
	}
}
