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
	int n,m; cin >> n >> m;
	bool ok = false;
	vector<string> v(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
	}
	for(int i=0;i<n-1;++i){
		for(int j=0;j<m-1;++j){
			int cnt = (v[i][j]=='0') + (v[i][j+1]=='0') + (v[i+1][j]=='0') + (v[i+1][j+1]=='0');
			if(cnt>=2){
				ok = true;
				break;
			}
		}
		if(ok) break;
	}
	int ans = 0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(v[i][j]=='1') ans++;
		}
	}
	if(ans==m*n) ans--;
	ans--;
	cout << ans + (ok&1) << endl;
}
