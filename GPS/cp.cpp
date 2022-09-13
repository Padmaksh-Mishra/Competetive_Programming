# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "NO" << endl
# define YES cout << "YES" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;

const ll MOD = 1e9 +7;
const int N = 1e5 + 1;

void setIO(string name = "sublime");

void solve(){
	int k; cin >> k;
	string s; cin >> s;
	vi goods;
	//goods.pb(0);
	int n = s.size();
	int sum = 0;
	for(int i=0;i<(n/2);++i){
		if(s[i]=='L') goods.pb(n-(2*i)-1);
	}
	int l = (n/2);
	//if(n&1) k++;
	for(int i=l;i<n;++i){
		if(s[i]=='R') goods.pb(i-n+i+1);
	}
	for(int i=0;i<n;++i){
		if(s[i]=='L') sum+=i;
		else sum+=(n-i-1);
	}
	int x = goods.size();
	sort(all(goods),greater<int>());
	x = min(x,k);
	// cout << sum << " ";
	for(int i=0;i<x;++i){
		sum+=goods[i];
		cout << sum << " ";
	}
	int m = k-x;
	//if(n&1) m--;
	while(m>0){
		--m;
		cout << sum << " ";
	}
	cout << endl;
}

signed main(){

    JAI SHREE RAM

    setIO();	//Does not work with Google 	
    int TC = 1;
    cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}

void setIO(string name) {  
#ifndef ONLINE_JUDGE
	if((ll)name.size() > 0){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
#endif
}

//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 