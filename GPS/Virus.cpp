//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,m; cin >> n >> m;
	int sf = 0;
	vector<int> v(m);
	for(int i=0;i<m;++i){
		cin >> v[i];
	}	
	sort(v.begin(), v.end());
	if(m==1) {
		cout << 2 << endl;
		return;
	}
	vector<int> difs;
	for(int i=0;i<m;++i){
		difs.push_back(((n-v[i%m]+v[(i+1+m)%m])%n)-1);
		//deb(difs[i]);
	}
	int ans = 0;
	sort(difs.begin(), difs.end());
	for(int i=1;i<=m;++i){

		ans+=max(0,difs[m-i] - sf-1);
		sf+=2;
	}
	cout << n-ans << endl;
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