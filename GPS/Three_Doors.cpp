//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	int ary[4];
	for(int i=1;i<4;++i) {
		cin >> ary[i];
		// if(ary[i]==i){
		// 	cout << "NO" << endl;
		// 	return;
		// }
	}
	// if(ary[n]==0){
	// 	cout << "NO" << endl;
	// 	return;
	// }
	int tmp=2;
	while(tmp--){
		if(ary[n]==0){
		cout << "NO" << endl;
		return;
		}
		n = ary[n];
	}
	cout << "YES" << endl;
	return;
	

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