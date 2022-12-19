//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
vector<int> arr(1e9);
vector<ll> hsh(1e9 + 1);
void solve(){
	int n,q; cin >> n >> q;
	int l,r,v;
	while(n--){
		cin >> l >> r >> v;
		arr[l]+=v;
		arr[r]-=v;
	}
	hsh[0] = 0;
	ll sum = arr[0] = hsh[1];
	for(int i=1;i<1e9;++i){
		sum+=arr[i];
		hsh[i+1] = hsh[i] + sum;
	}	
	while(q--){
		cin >> l >> r;
		cout << hsh[r-1] - hsh[l-1] << endl;
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