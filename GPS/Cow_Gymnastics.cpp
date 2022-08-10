//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int k,n; cin >> k >> n;  // n<20 | k <10
	int ips[k][n+1];
	
	for(int i=0;i<k;++i){
		for(int j=1;j<n+1;++j){
			int tmp; cin >> tmp;
			ips[i][tmp] = j;
		}
	}
	map<pair<int,int>,int> m;

	for(int i=1;i<n+1;++i){
		for(int j=1;j<n+1;++j){
			for(int l=0;l<k;++l){
				if(ips[l][i] < ips[l][j]) m[{i,j}]++;
			}
		}
	}
	int ans = 0;
	for(auto val : m){
		if(val.second==k) ans++;
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