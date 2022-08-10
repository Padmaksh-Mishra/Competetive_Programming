//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);
vector<ll> arr(200002);
void solve(){
	int n; cin >> n;
	int tmp; 
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		arr[i+1] = arr[i] + tmp;
	}
	ll maxSum=arr[1],minSum=arr[0];

	for (int i = 1; i < n+1; ++i)
	{
		maxSum = max<ll>(maxSum,arr[i]-minSum);
		minSum = min<ll>(minSum,arr[i]);
	}

	cout << maxSum << endl;
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