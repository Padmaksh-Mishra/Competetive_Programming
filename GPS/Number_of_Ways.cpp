//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
ll f[1000001];
void factorial(){
	f[0]=1;
	f[1]=1;
	for(int i=2;i<1000001;++i) f[i] = (f[i-1]*i)%MOD;
}
void solve(){
	int n; cin >> n;
	ll sum = 0;
	int ary[n];
	for(int i=0;i<n;++i) {
		cin >> ary[i];
		sum+=ary[i];
	}
	if(sum%3!=0) {
		cout << 0 << endl;
		return;
	}
	sum /=3;
	int i=0,j=n-1;  
	int tmp = 0;  
	for(i=0;i<n;++i){
		tmp+=ary[i];
		if(tmp==sum) break;
	}
	tmp=0;
	for(j=n-1;j>=0;--j){
		tmp+=ary[j];
		if(tmp==sum) break;
	}
	int zero = 0;
	for(i = i+1;i<j;++i){
		if(ary[i]!=0) break;
		zero++;
	}
	if(zero==n-2){
		//deb(zero);
		cout << f[zero+1]/(f[zero-1]*2)<< endl;
		return;
	}
	if(j-i<1){
		cout << 0 << endl;
		return;
	}
	ll ans = zero+1;
	zero=0;
	for(int k=j-1;k>i;--k){
		if(ary[k]!=0) break;
		zero++;
	}
	
	ans *= (zero+1);
	cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything
    factorial();
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
