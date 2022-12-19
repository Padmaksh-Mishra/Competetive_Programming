//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int size = 4*1e5;
using namespace std;

int bexpo(int n,int p);
int e[size];
void solve(){
	int n,x; cin >> n >> x;
	for(int i = 0;i<x;i++) e[i] = i+1;
	for(int i = 0;i<n;i++) cin >> e[i+x];
	sort(e,e+n+x);
	ll ans = 0;
	for(int i = 1;i<n+x;i++) deb(e[i]),ans = ans + abs(e[i]-e[i-1]);
	cout << ans << endl;
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
