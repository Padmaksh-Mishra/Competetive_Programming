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
	map<ll,vll> m;
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		m[tmp%k].emplace_back(tmp);
	}	    
	vll residue;
	ll ans = 0;
	for(auto val : m){
		for(auto cost : val.s){
			if(siz(m[k-val.f])){
				ans+=(m[k-val.f][0] + cost)/k;
				m[k-val.f].erase(m[k-val.f].begin());
			}else residue.emplace_back(cost);
		}
	}
	//ans/=2;
	sort(all(residue));
	for(int i=0;i<siz(residue)-1;++i){
		ans+=(residue[i]+residue[i+1])/k;
	}
	cout << ans << endl;
}
