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
	// vll ps(n+1);
	// for(int i=0;i<n;++i){
	// 	ll tmp; cin >> tmp;
	// 	ps[i+1] = ps[i] + tmp*((i%2==0)?1:-1);
	// 	// deb(ps[i+1]);
	// }
	// ll ans;
	// for(int i=1;i<=n;++i){
	// 	if(ps[i]+((ps[n]-ps[i])*((i%2==0)?1:-1))==0){
	// 		ans = i;
	// 		cout << 2 << endl;
	// 		cout << 1 << " " << i << endl;
	// 		cout << i+1 << " " << n << endl;	
	// 		return;
	// 	}
	// }
	// cout << -1 << endl;
	vll ips(n);
	vector<pair<ll,ll>> ans;
	ll sum = 0;
	for(int i=0;i<n;++i){
		cin >> ips[i];
		sum+=(ips[i]*(i&1?-1:1));
	}
	for(int i=0;i<n;i+=2){
		if(ips[i]==ips[i+1]){
			ans.pb(make_pair(i,i+1));
		}
		else{
			ans.pb(make_pair(i,i));
			ans.pb(make_pair(i+1,i+1));
		}
	}
	if(sum&1) cout << -1 << endl;
	else{
		cout << siz(ans) << endl;
		for(auto val : ans){
			cout << val.f+1 << " " << val.s+1 << endl;
		}
	}
	return;
}
