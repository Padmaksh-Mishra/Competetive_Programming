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
	map<string,int> name;
	ll t = 1;
	vll m(2e5 + 1);
	for(int i=0;i<n;++i){
		string a,b; cin >> a >> b;
		if(!name[a]){
			name[a] = t;
			++t;
		}
		if(!name[b]){
			name[b] = t;
			++t;
		}
		m[name[a]]=name[b];
	}
	// map<string,int> supervis;
	vll supervis(2e5 + 1);
	for(auto val : m){
		if(val==0) continue;
		if(supervis[val]) continue;
		else supervis[val] = 1;
		// deb(val.f);
		map<int,int> vis;
		int go = val;
		while(m[go]){
			if(vis[m[go]]){
				cout << "No" << endl;
				return;
			}
			vis[m[go]] = 1;
			supervis[m[go]] = 1;
			go = m[go];
		}
	}
	cout << "Yes" << endl;
}
