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
    cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 
ll hm2(ll n){
	for(int i=0;;++i){
		ll tmp = (1<<i);
		if(n&tmp) {
			return i;
		}
		if(tmp>n) return 0;
	}
}
void solve(){
	ll n; cin >> n;
	vll ips(n);
	ll tt = 0;
	for(int i=0;i<n;++i) cin >> ips[i],tt+=hm2(ips[i]);
	ll more = n-tt;
	vll cando;
	for(int i=0;i<n;++i){
		cando.pb(hm2(i+1));
	}
	sort(all(cando),greater<ll>());
	if(more<=0){
		cout << 0 << endl;
	}else{
		ll i = 0;
		while(more>0&&i<=n){
			more-=cando[i];
			++i;
		}
		if(i>n) cout << -1 << endl;
		else cout << i << endl;
	}
}