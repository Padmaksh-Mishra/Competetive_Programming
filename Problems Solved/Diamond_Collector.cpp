//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,k; cin >> n >> k;
	vector<int> diamonds(n+1,0);
	for(int i=1;i<n+1;++i) cin >> diamonds[i];
	sort(diamonds.begin(), diamonds.end());
	for(int i=1;i<n+1;++i) cout << diamonds[i] << " ";
	cout << endl;
	int j = 2;
	int ans = 0;
	for(int i=1;i<n;++i){
		if(i==j) j++;
		while(diamonds[j]-diamonds[i]<=k&&j<=n){
			deb(i);deb(j);
			ans++;
			j++;
		}
	}	
	cout << ans << endl;
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
    //cin >> TC;
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