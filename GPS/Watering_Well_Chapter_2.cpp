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
vi t(500001),w(500001);
void solve(){
	int n; cin >> n;
	int x,y;
	int wx,wx2,wy,wy2,tx,tx2,ty,ty2;
	wx=wx2=wy=wy2=tx=tx2=ty=ty2=0;
	for(int i=0;i<n;++i){
		cin >> x >> y;
		tx = (tx+x)%MOD;
		ty = (ty + y)%MOD;
		tx2 = ((tx2 + (x*x)%MOD)%MOD);
		ty2 = ((ty2 + (y*y)%MOD)%MOD);
	}
	int q; cin >> q;
	for(int i=0;i<q;++i){
		cin >> x >> y;
		wx = (wx+x)%MOD;
		wy = (wy + y)%MOD;
		wx2 = ((wx2 + x*x)%MOD);
		wy2 = ((wy2 + y*y)%MOD);
	}
	int ans = (n*wx2)%MOD + (n*wy2)%MOD + (q*tx2)%MOD + (q*ty2)%MOD - (2*(tx)*(wx))%MOD - (2*(ty)*(wy))%MOD;
	cout << (ans+MOD)%MOD << endl;
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