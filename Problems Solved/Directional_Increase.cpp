//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int arr[200001];
int tst[200001];
void solve(){
	int n; cin >> n;    
	ll sum = 0;
	int i,k=-1;
	for(int k=0;k<n;++k) cin >> arr[k];
	for(i=0;i<n;++i){

		sum+=arr[i];
		if(sum==0&&k==-1) k = i; 
		if(sum<0){
			cout << "NO" << endl;
			return;
		} 
	}
	bool ok = true;
	for(int h = k+1;h<n;++h){
		if(arr[h]!=0) ok = false;
	}
	if(sum==0&&ok){
		cout << "YES" << endl;
		return;
	}
	cout << "NO" << endl;
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
