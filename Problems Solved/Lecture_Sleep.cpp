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
	ll n,m; cin >> n >> m;
	vll lec(n);
	vector<bool> awake(n);
	for(int i=0;i<n;++i) cin >> lec[i];
	for(int i=0;i<n;++i) {
		ll tmp; cin >> tmp;
		awake[i] = (tmp==1);
	}
	ll gain = 0;
	ll i,ans=0,obv=0;
	for(i=0;i<m;++i){
		if(!awake[i]) gain+=lec[i];
		else obv+=lec[i];
	}
	ans=max(ans,gain);
	for(i=m;i<n;++i){
		if(!awake[i-m]) gain-=lec[i-m];
		if(!awake[i]) gain+=lec[i];
		else obv+=lec[i];
		ans=max(ans,gain);
	}
	ans+=obv;
	cout << ans << endl;
}
