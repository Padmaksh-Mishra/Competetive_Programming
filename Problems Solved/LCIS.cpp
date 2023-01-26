# include <bits/stdc++.h>
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define ll long long
# define f first
# define s second
# define siz(x) (int)(x).size()
# define vll vector<ll>
# define pll pair<ll,ll>
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
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
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
	vll a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}	    
	ll m; cin >> m;
	vll b(m);
	for(int i=0;i<m;++i){
		cin >> b[i];
	}

	//lcs
	vector<vll> dp(n+1,vll(m+1,0));
	dp[0][0] = 0;
	for(int i=0;i<n+1;++i){
		for(int j=0;j<m+1;++j){
			if(i<n) dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j<m) dp[i][j+1] = max(dp[i][j+1],dp[i][j]);
			if(i<n&&j<m) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+(a[i]==b[j]));
		}
	}

	ll indx = dp[n][m];
	vll lcs(indx);
	ll i=n,j=m;
	while(indx>0){
		if(a[i-1]==b[j-1]){
			lcs[indx-1] = a[i-1];
			i--;
			j--;
			indx--;
		}else if(dp[i][j-1]>dp[i-1][j]){
			j--;
		}else{
			i--;
		}
	}
	for(auto val : lcs){
		cout << val << " ";
	}
	cout << endl;

	//lis
	ll s = siz(lcs);
	vll dpp(s,1);
	vll par(s,-1);

	for(int i=0;i<s;++i){
		for(int j=0;j<i;++j){
			if((lcs[i]>lcs[j])&&(dpp[i]<dpp[j]+1)){
				dpp[i] = dpp[j]+1;
				par[i] = j;
			}
		}
	}
	ll len = 0,p=-1;
	for(int i=0;i<s;++i){
		if(len<dpp[i]){
			len = dpp[i];
			p = i;
		}
	}
	cout << len << endl;
	vll lcis;
	while(p!=-1){
		lcis.emplace_back(lcs[p]);
		p = par[p];
		len--;
	}
	reverse(all(lcis));
	for(auto val : lcis){
		cout << val << " ";
	}
}
