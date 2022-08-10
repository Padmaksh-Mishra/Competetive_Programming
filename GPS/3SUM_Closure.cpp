//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
#define for(i, st, n) for (auto i = st-(st > n); (st > n)?(i >= n):(i < n); i += 1-2*(st > n))

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void solve(){
	int n; cin >> n;
	vector<int> hsh(4,0);
	int arr[n];
	for(i,0,n) cin >> arr[i];
	if(n==3){
		int sum=0;
		for(i,0,n) sum+=arr[i];
		bool found = false;
		for(i,0,n) if(arr[i]==sum) {
			found=true;
			break;
		}
		if(found) cout << "YES" << endl;
		else cout << "NO" << endl;
	}else{
		ll sum = 0;
		for(i,0,n){
			sum+=arr[i];
			if(arr[i]==0) hsh[1]++;
			else if(arr[i]<0) hsh[0]++;
			else if(arr[i]>0) hsh[2]++;
			else hsh[3]++;
		}
	bool poss = true;
	if(sum!=0) poss = false;

	if(hsh[3]>0||hsh[0]>1||hsh[2]>1) poss = false;
	if(poss) cout << "YES" << endl;
	else cout << "NO" << endl;
	}
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