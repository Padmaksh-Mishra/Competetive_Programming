//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

using namespace std;

int n,m;
char spot[100][101]; //100+1 for \0
char plain[100][101];
bool ok(int i){
	for(int j=0;j<n;++j){
		for(int k=0;k<n;++k){
			if(spot[j][i]==plain[k][i]){
				return false;
			}
		}
	}
	return true;
}
void solve(){
	cin >> n >> m;
	
	for(int i=0;i<n;++i){
		cin >> spot[i];
	}
	
	for(int i=0;i<n;++i){
		cin >> plain[i];
	}

	int ans = 0;
	for(int i=0;i<m;++i){
		if(ok(i)) ans++;
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
