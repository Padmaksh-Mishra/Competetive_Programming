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
# define pb push_back

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
	vector<vll> mp(n,vll(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin >> mp[i][j];
		}
	}
	if(n>m)	    
	vector<string> ans;
	// row-wise
	for(int i=0;i<n;++i){
		ll mine = INF;
		for(int j=0;j<m;++j){
			mine = min(mine,mp[i][j]);
		}
		for(int j=0;j<m;++j){
			mp[i][j]-=mine;
		}
		if(mine!=0){
			string s = "row ";
			s+=to_string(i+1);
			//deb(s);
			while(mine--) ans.emplace_back(s);
		}
	}
	//coloumn-wise
	for(int i=0;i<m;++i){
		ll mine = INF;
		for(int j=0;j<n;++j){
			mine = min(mine,mp[j][i]);
		}
		for(int j=0;j<n;++j){
			mp[j][i]-=mine;
		}
		if(mine!=0){
			string s = "col ";
			s+=to_string(i+1);
			while(mine--) ans.emplace_back(s);
		}

	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(mp[i][j]!=0){
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << siz(ans) << endl;
	for(auto val : ans){
		cout << val << endl;
	}
}
