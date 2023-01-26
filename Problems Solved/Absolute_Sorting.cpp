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
	vll v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}	    
	// ll mx = 0,mn = 1e9;
	// for(int i=0;i<n-1;++i){
	// 	if(v[i]>v[i+1]){
	// 		mx = max(mx,((v[i]+v[i+1]+1)/2));
	// 	}else{
	// 		mn = min(mn,((v[i]+v[i+1])/2));
	// 	}
	// }
	// auto sch = [&](ll k)->bool{
	// 	for(int i=0;i<n-1;++i){
	// 		if(abs(v[i]-k)>abs(v[i+1]-k)){
	// 			return false;
	// 		}
	// 	}
	// 	return true;	
	// };
	// if(sch(mx)) cout << mx << endl;
	// else if(sch(mn)) cout << mn << endl;
	// else cout << -1 << endl;

	auto sch = [&](ll k)->ll{
		for(int i=0;i<n-1;++i){
			if(abs(v[i]-k)>abs(v[i+1]-k)){
				return i;
			}
		}
		return n;	
	};
	ll s=0,e=1e9,mid;
	while(e-s>1){
		mid = s + ((e-s)>>1);
		ll bad = sch(mid);
		if(bad==n){
			cout << mid << endl;
			return;
		} 
		if(v[bad]>v[bad+1]){
			s = mid+1;
		}else{
			e = mid;
		}
	}
	if(sch(s)==n) cout << s << endl;
	else if(sch(e)==n) cout << e << endl;
	else cout << -1 << endl;
}
