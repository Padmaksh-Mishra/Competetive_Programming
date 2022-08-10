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
	multiset<int> ms;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		ms.insert(tmp);
	}	
	vector<int> ans;
	while(m--){
		int prce; cin >> prce;
		auto it = ms.upper_bound(prce);
		if(it==ms.begin()) ans.push_back(-1);
		else {
			ans.push_back(*(--it));
			ms.erase(it);
		}
	}
	for(auto val:ans) cout << val << endl;
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