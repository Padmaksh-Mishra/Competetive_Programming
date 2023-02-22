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
ll maxval;
vll vals;
vector<vll> dp(40001,vll(600,0));

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
    //setIO("sublime");    //Does not work with Google     
    ll TC = 1;
    cin >> TC;

    for(int i=1;i<10;++i){
    	vals.emplace_back(1*i);
    	vals.emplace_back(11*i);    	
    }
    for(int i=1;i<10;++i){
    	for(int j=0;j<10;++j){
    		vals.emplace_back(101*i+10*j);
	    	vals.emplace_back(1001*i+110*j);
    	}
    }
    for(int i=1;i<5;++i){
    	for(int j=0;j<10;++j){
    		for(int k=0;k<10;++k){
    			vals.emplace_back(10001*i+1010*j+100*k);
    		}
    	}
    }
    maxval = siz(vals);
    // deb(maxval);
    ll maxs = 40000;
    sort(all(vals));
   
    dp[0][0]=1;
    for(int v=0;v<maxval+1;++v){
    	for(int s=0;s<maxs+1;++s){
    		if(v<maxval) dp[s][v+1]=(dp[s][v+1]+dp[s][v])%MOD;
    		if(v>0&&s+vals[v-1]<maxs+1) dp[s+vals[v-1]][v]=(dp[s+vals[v-1]][v]+dp[s][v])%MOD;
    	}
    }


    for(int i=0;i<TC;++i){
        //cout << "Case #" << i+1 << ": ";
        solve();
    }
    return 0;
}

// Do something good 

void solve(){
	ll n; cin >> n;
	cout << dp[n][maxval]%MOD << endl;	    
}
