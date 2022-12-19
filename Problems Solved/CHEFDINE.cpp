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
const ll INF = 1e5 + 9; 
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
	ll n,k; cin >> n >> k;
	map<ll,ll> m;
	vll type(n);
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		m[tmp] = INF;
		type[i] = tmp;
	}	    
	for(int i=0;i<n;++i){
		ll time; cin >> time;
		m[type[i]] = min(m[type[i]],time);
	}
	vll s;
	for(auto val : m){
		s.emplace_back(val.s);
	}
	//deb(siz(m));
	if(siz(s)<k){
		cout << -1 << endl;
	}else{
		sort(all(s));
		ll i=0;
		ll ans = 0;
		for(auto val : s){
			ans+=val;
			i++;
			if(i==k) break;
		}
		cout << ans << endl;
	}
}
