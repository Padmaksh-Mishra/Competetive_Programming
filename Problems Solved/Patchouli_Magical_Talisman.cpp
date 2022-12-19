//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
int arr[200000];

int fstbit(int n){
	int fb = 0;
	while(n){
		if(n&1) return fb;
		n>>=1;
		fb++;
	}
	return 0;
}
void solve(){
	int n; cin >> n;
	int ods,evn; ods=evn=0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		if(arr[i]&1) ods++;
		else evn++;
	}
	if(ods==0){
		int bitc = MOD;
		for(int i=0;i<n;i++){
			bitc = min(bitc,fstbit(arr[i]));
		}
		cout << bitc + n-1 << endl;
	}
	else cout << evn << endl;
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
