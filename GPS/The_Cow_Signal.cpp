# include <bits/stdc++.h>
# define DEATH ios_base::sync_with_stdio(false); 
# define AWAITS cin.tie(NULL); 
# define YOU cout.tie(NULL);
# define int long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "No" << endl
# define YES cout << "Yes" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (int)(x).size()
# define vi vector<int>
# define all(x) (x).begin(), (x).end()

using namespace std;

const int MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name = "sublime");

void solve(){
	int m,n,k; cin >> m >> n >> k;
	vector<string> v(m);
	for(int i=0;i<m;++i){
		cin >> v[i];
	}
	for(int i=0;i<m;++i){
		for(int l=0;l<k;++l){
			for(int j=0;j<n;++j){
				for(int x=0;x<k;++x){
					cout << v[i][j];
				}
			}
			cout << endl;
		}
	}
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
    int TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((int)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}