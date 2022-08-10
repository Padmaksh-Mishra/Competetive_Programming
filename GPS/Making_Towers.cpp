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
	int seq[n];
	map<int,vector<int>> m;
	for(int i=0;i<n;++i) {
		cin >> seq[i];
		m[seq[i]].push_back(i);
	}
	vector<int> ans(n+1,0);
	for(auto &val : m){
		int tmp = 1;
		for(auto it = val.second.begin()+1;it!=val.second.end();++it){
			if((*it-*(it-1))&1) tmp++;
			else if((*it-*(it-2))&1) tmp++,it++;
			else tmp = 1;
			ans[val.first] = max(ans[val.first],tmp);
		}
		ans[val.first] = max(ans[val.first],tmp);

	}

	for(int i = 1;i<=n;++i){
		cout << ans[i] << " ";
	}
	cout << endl;
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