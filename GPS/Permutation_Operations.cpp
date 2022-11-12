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

void solve(){
	ll n; cin >> n;
	vll ips(n+1,0);
	vector<pair<ll,ll>> sums;
	ll maxi; cin >> maxi;ips[1] = maxi;
	for(ll i=2;i<=n;++i){
		cin >> ips[i];
		// deb(maxi);
		if(ips[i]<maxi) {
			// deb(i);
			sums.push_back(make_pair(maxi-ips[i],i));
			maxi = ips[i];
		}else maxi = max(maxi,ips[i]);
	}
	ll t=1;
	sort(all(sums));
	for(int i=0;i<siz(sums)&&t<n;++i){
		ll sum = sums[i].f;
		ll idx = sums[i].s;
		while(sum>0){
			sum-=t;
			cout << idx << " ";
			t++;
		}
	}
	for(int i=t;i<=n;++i) cout << n << " ";
	cout << endl;
}
