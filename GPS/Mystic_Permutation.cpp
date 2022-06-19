//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int q[1001],ans[1001];

void solve(){
	int n; cin >> n;

	for(int i=1;i<n+1;++i){
		cin >> q[i];
		ans[i]=i;
	}

	if(n==1){
		cout << -1 << endl;
		return;
	}

	for(int i=1;i<n;++i){
		if(ans[i]==q[i]) swap(ans[i],ans[i+1]);
	}
	if(ans[n]==q[n]) swap(ans[n],ans[n-1]);

	// final check
	for(int i=1;i<n;++i){
		if(ans[i]==q[i]) swap(ans[i],ans[i+1]);
	}
	// for(int i=1;i<n;++i){
	// 	if(ans[i]>ans[i+1]) if(ans[i]!=q[i+1]) swap(ans[i],ans[i+1]);
	// }

	for(int i=1;i<n+1;++i) cout << ans[i] << " ";
	cout << endl;

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
