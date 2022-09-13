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

const int MOD = 1000000007;
const int N = 1e5 + 1;

void setIO(string name = "sublime");

void solve(){
	int n; cin >> n;
	vector<vector<int>> b(n);
	for(int i=0;i<n;++i){
		int x,y; cin >> x >> y;
		b[i].pb(x);
		b[i].pb(y);
		x = (x*x)%MOD;
		y = (y*y)%MOD;
		b[i].pb(x+y);
	}
	int q; cin >> q;
	vector<vector<int>> a(q);
	for(int i=0;i<q;++i){
		int x,y; cin >> x >> y;
		a[i].pb(x);
		a[i].pb(y);
		x = (x*x)%MOD;
		y = (y*y)%MOD;
		a[i].pb(x+y);
	}
	int distance = 0;
	for(int i=0;i<q;++i){
		// cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << endl;
 		for(int j=0;j<n;++j){
 			// distance%=MOD;
 			int k = a[i][2]+b[j][2] - ((((a[i][0]*b[j][0])+(a[i][1]*b[j][1]))%MOD)<<1);
 			k%=MOD;
 			distance+=k;
 			distance%=MOD;
 			// cout << b[j][0] << " " << b[j][1] << " " << b[j][2] << endl;
 		}
	}
	cout << distance << endl;
}

int32_t main(){

    DEATH AWAITS YOU

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	cout << "Case #" << i+1 << ": ";
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