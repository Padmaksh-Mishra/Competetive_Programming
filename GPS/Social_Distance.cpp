//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);


void solve(){
	int n,m; cin >> n >> m;
	int tmp;
	vector<int> pops;
	ll motai = 0;
	for(int i=0;i<n;i++) {
		cin >> tmp;
		pops.push_back(tmp);
	}
	sort(pops.begin(),pops.end());
	for(int i=n-1;i>0;i--) {
		//deb(pops[i]);
		motai+=pops[i]+1;
	}
	motai +=pops[n-1]+1;
	//deb(motai);
	if(motai<=m) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

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
