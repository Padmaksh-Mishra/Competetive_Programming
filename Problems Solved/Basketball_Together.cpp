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

const ll MOD = 1e9 +7;
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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; 
	float d; 
	cin >> n >> d;
	vll p(n);
	for(int i=0;i<n;++i) cin >> p[i];
	sort(all(p),greater<>());
	ll tms = n;
	ll i=0;
	while(tms>0&&i<n){
		ll tmp = ceil(d/p[i]);
		if(tmp*p[i]==d) tmp++;
		// deb(tmp);
		if(tms>=tmp){
			i++;
			tms-=tmp;
		}else break;
		// deb(tms);
	}  
	cout << i << endl;  
}
