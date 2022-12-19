//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int ans[100001];
void solve(){11
	int n; cin >> n;
	int ans[n+1];
	if(n%2==0){
		cout << n << " ";
		n--;
	}
	for(int i=1;i<=n;++i){
		ans[i] = n-i + 1;
	}
	if(n&1&&n!=1){
		swap(ans[1],ans[2]);
		swap(ans[n/2],ans[(n/2)+1]);
	}
	for(int i=1;i<=n;++i) cout << ans[i] << " ";
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