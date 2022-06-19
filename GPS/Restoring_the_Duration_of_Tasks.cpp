//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	int s[n],f[n];
	int d[n];
	for(int i=0;i<n;++i) cin >> s[i];
	for(int i=0;i<n;++i) cin >> f[i];
	for(int i=0;i<n;++i) d[i] = -1;
	for(int i=0;i<n-1;++i){
		if(f[i]-s[i]>=0) if(d[i]==-1) d[i] = f[i]-s[i];
		if(s[i+1]<f[i]) d[i+1] = f[i+1] - f[i];
	}
	if(d[n-1]==-1) d[n-1] = f[n-1] - s[n-1];
	for(int i=0;i<n;++i){
		cout << d[i] << " ";
	}
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
