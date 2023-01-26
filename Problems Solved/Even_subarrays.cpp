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
vll sqs;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google 
    ll i = 0,sq=0;
    while(sq<2*N){
    	sqs.emplace_back(sq);
    	i++;
    	sq=(i*i);
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
	ll n; cin >> n;
	vll ips(n);
	for(int i=0;i<n;++i){
		cin >> ips[i];
	}
	ll ex = 0;
	for(auto sq : sqs){
		if(sq>2*n) break;
		vll m(2*n+1);
		ll x = 0;
		m[0]++;
		for(int i=0;i<n;++i){
			x^=ips[i];
			if((x^sq)<=2*n) ex+=m[(x^sq)];
			m[x]++;
		}
	}
	ll ans = n*(n+1)/2;
	cout << ans - ex << endl;
}
