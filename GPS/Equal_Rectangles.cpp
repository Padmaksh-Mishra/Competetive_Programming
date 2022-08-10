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
	vector<int> a(4*n);
	for(int i=0;i<(4*n);++i) cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> m;
	for(int i=0;i<(4*n)-1;i+=2){
		// cout << a[i] << " " << a[i+1] << endl;
		if(a[i]!=a[i+1]){
			cout << "NO" << endl;
			return;
		}
		m.push_back(a[i]);
	}	
	ll prod = m[0]*m[(2*n)-1];
	for(int i=1;i<n;++i){
		if(prod!=(m[i]*m[(2*n)-i-1])){
			cout << "NO" << endl;
			return;	
		}
	}
	cout << "YES" << endl;

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