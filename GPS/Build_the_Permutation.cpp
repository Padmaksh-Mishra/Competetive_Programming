//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n,a,b; cin >> n >> a >> b;
	if(abs(a-b)>1){
		cout << -1 << endl;
		return;
	}
	if(a+b>n-2){
		cout << -1 << endl;
		return;
	}
	int c = min(a,b);
	vector<int> ans;
	ans.push_back(1);
	for(int i=1;i<=c;++i){
		ans.push_back(2*i+1);
		ans.push_back(2*i);
	}
	for(int i=2*c+2;i<=n;++i) ans.push_back(i);

	if(b>a){
		cout << ans[n-1] << " ";
		for(int i = 0;i<n-1;++i) cout << ans[i] << " ";
	}
	else if(a>b){
		swap(ans[n-2],ans[n-1]);
		for(int i = 0;i<n;++i) cout << ans[i] << " ";	
	}else{
		for(int i = 0;i<n;++i) cout << ans[i] << " ";
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