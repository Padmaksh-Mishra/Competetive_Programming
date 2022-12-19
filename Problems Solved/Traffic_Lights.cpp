//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int x,n; cin >> x >> n;
	vector<int> ans;
	set<int> s;
	s.insert(0);
	s.insert(x);
	multiset<int> ms;
	ms.insert(x);
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		s.insert(tmp);
		auto it = s.find(tmp);
		// deb(*it);
		int a = abs((*it)-*(--it));
		++it;
		int b = abs((*it)-*(++it));
		ms.insert(a);
		ms.insert(b);
		// deb(a);
		// deb(b);
		int c = a + b;
		ms.erase(ms.find(c));
		it = ms.end();
		ans.push_back(*(--it));
	}
	for(auto val : ans) cout << val << " ";
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