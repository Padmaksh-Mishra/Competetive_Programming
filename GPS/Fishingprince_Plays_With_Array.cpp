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
// ll m; 
// vector<pair<ll,ll>> expand(vll &a){
// 	vector<pair<ll,ll>> tmp;
// 	for(auto val : a){
// 		ll cnt = 1;
// 		while(val%m==0){
// 			cnt *= (m);
// 			val/=m;
// 		}
// 		if(tmp.empty()||tmp.back().f!=val) tmp.emplace_back(make_pair(val,cnt));
// 		else tmp.back().s+=cnt;
// 	}
// 	return tmp;
// }
void solve(){
	ll n,m,k;
	cin >> n >> m;
	vll a(n);
	for(int i=0;i<n;++i) cin >> a[i];
	cin >> k;
	vll b(k);
	for(int i=0;i<k;++i) cin >> b[i];

	auto expand = [m](vll &ips)->vector<pair<ll,ll>>{
		vector<pair<ll,ll>> tmp;
		for(auto val : ips){
			ll cnt = 1;
			while(val%m==0){
				cnt *= m;
				val/=m;
			}
			if(tmp.empty()||tmp.back().f!=val) tmp.emplace_back(make_pair(val,cnt));
			else tmp.back().s+=cnt;
		}
		return tmp;
	};
	
	vector<pair<ll,ll>> fa,fb;
	fa = expand(a);
	fb = expand(b);

	if(fa==fb){
		cout << "YES" << endl;
	}else cout << "NO" << endl;
}
