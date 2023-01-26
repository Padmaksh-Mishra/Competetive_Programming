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
	ll k,x; cin >> k >> x;
	auto ok = [&](ll m){
		ll e=0;
		if(m<k+1){
			e = m*(m+1)/2;
		}else{
			e = k*(k+1)/2;
			m-=k;
			e+= k*(k-1)/2;
			e-= (k-1-m)*(k-m)/2;
		}
		// deb(m);
		// deb(e);
		if(e<0) return false;
		return (e<x);
	};

	ll s=1,e=2*k+1,mid;
	while(e-s>1){
		mid = s+(e-s)/2;
		if(ok(mid)){
			s=mid;
		}else{
			e=mid-1;
		}
	}
	if(ok(e)){
		cout << e+1 << endl;
	}else if(ok(s)){
		cout << s+1 << endl;
	}else cout << 1 << endl;
}
