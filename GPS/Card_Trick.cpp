//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int a[200000],b[200000];
void solve(){
	int n; cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	int m; cin >> m;
	ll sm = 0;
	for(int i=0;i<m;i++){
		int tmp ; cin >> tmp;
		sm+=tmp;
	}
	int topmost,ansi = 0;
	//deb(a[ansi]);
	ansi = (ansi+sm)%n;
	//deb(ansi);
	cout << a[ansi] << endl;
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
