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
	vll a(n),b(m);

	for(int i=0;i<n;++i){
		cin >> a[i];
	}	    
	for(int i=0;i<m;++i){
		cin >> b[i];
	}
	auto check = [&](ll r)->bool{
		for(int i=0;i<n;++i){
			auto itr1 = lower_bound(all(b),a[i]-r);
			ll val1 = (itr1==b.end()) ? INF : *itr1;
			if((abs(a[i]-val1)>r)){
				return false;
			}
		}
		return true;
	};

	ll s=0,e=1e10,mid;
	while(e-s>1){
		mid = (s+e)>>1;
		if(check(mid)){
			e = mid;
		}else s = mid+1;
	}
	if(check(s)) cout << s << endl;
	else if(check(mid)) cout << mid << endl;
	else cout << e << endl;
}
