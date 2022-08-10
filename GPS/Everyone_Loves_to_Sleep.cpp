//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 24*60;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,h,m; cin >> n >> h >> m;
	int slep = (h*60)+m;
	set<int> alm;
	while(n--){
		int a,b; cin >> a >> b;
		int am = (a*60)+b;
		alm.insert(am);
	}	
	int ans;
	if(alm.lower_bound(slep)==alm.end()){
		ans = ((*alm.begin())-slep+MOD)%MOD;
	}else ans = ((*alm.lower_bound(slep)) - slep+MOD)%MOD;

	cout << ans/60 << " " << ans%60 << endl;
}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}