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
	ll n; cin >> n;
	vector<vll> v;
	for(int i=0;i<n;++i){
		ll tmp; cin >> tmp;
		ll s=0,e=v.size(),mid;
		while(e-s>1){
			mid = (e+s)/2;
			if(v[mid].back()<tmp){
				e = mid;
			}else{
				s = mid+1;
			}
		}
		if(s!=v.size()&&v[s].back()<=tmp) v[s].emplace_back(tmp);
		else if(e!=v.size()&&v[e].back()<=tmp) v[e].emplace_back(tmp);
		else v.push_back({tmp});
	}	    
	for(auto val : v){
		for(auto ele : val) cout << ele << ' ';
		cout << endl;
	}
}
