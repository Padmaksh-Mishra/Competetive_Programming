# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define pb push_back
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9; 
const int N = 2e5 + 1;

void setIO(string name) {  
#ifndef ONLINE_JUDGE
    if((int)name.size() > 0){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
#endif
}

void solve();

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
    setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	vll arr(n);
	ll sum = 0;
	for(int i=0;i<n;++i){
		cin >> arr[i];
		sum+=arr[i];
	}	    
	if(sum%3){
		cout << 0 << endl;
		return;
	}
	ll tgt = sum/3;
	vector<vll> dp(n+1);
	//ll dp[n+1][tgt+1];
	for(int i=0;i<n;++i){
		for(int s=0;s<tgt+1;++s){
			if(s==0){
				dp[i][s] = 1;
			}
			dp[i+1][s] = dp[i][s];
			if(s+arr[i]<=tgt) dp[i+1][s+arr[i]] = dp[i][s+arr[i]]+dp[i][s];
		}
	}
	cout << (dp[n][tgt]/3) << endl;
}