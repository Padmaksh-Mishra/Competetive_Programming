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
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n,k; cin >> n >> k;
	vll v(n);
	ll maxi = -1;
	for(int i=0;i<n;++i){
		cin >> v[i];
		maxi = max(maxi,v[i]);
	}	   
	auto ok = [&v,n,k](ll t)->ll{
		ll sum = 0;
		ll tmp = 0;
		for(int i=0;i<n;++i){
			if(sum+v[i]>t){
				sum=0;
				tmp++;
			}
			sum+=v[i];
		}
		if(sum>0&&sum<=t) tmp++;
		return (tmp);
	};

	ll s=maxi,e=1e18 ,mid;
	while(e-s>1){
		mid = s + ((e-s)>>1);
		ll divs = ok(mid);
		if(divs>k){
			s = mid+1;
		}else{
			e = mid;
		}
	}
	if(ok(s)==k) cout << s << endl;
	else cout << e << endl;
	return;
}
