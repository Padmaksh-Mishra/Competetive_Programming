# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
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

using namespace std;
const ll MOD = 1e9 +7;
void setIO(string name = "sublime");

void solve(){
	int n,s; cin >> n >> s;
	vi v(n);
	vi ps(n+1,0);
	int lent = -1;
	for(int i=0;i<n;++i) cin >> v[i];
	for(int i=1;i<n+1;++i) ps[i] = ps[i-1] + v[i-1];
	int i,j=1,sum=0;
    for(i=0;i<n;++i){
        sum = ps[j] - ps[i];
        while(sum<=s&&j<=n){
        	j++;
        	sum = ps[j] - ps[i];
        }
        sum = ps[j-1] - ps[i];
        if(sum==s) lent = max(lent,j-i);
    }
    if(lent!=-1) lent = n - lent+1;
    cout << lent << endl;
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
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