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
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;

void solve(){
   int t,d,m; cin >> t >> d >> m;
   vi ips(m+2);
   ips[0] = 0;
   for(int i=1;i<=m;++i){
    cin >> ips[i];
   }
   ips[m+1] = d;
   //vi da(m+1);
   int sp = -1;
   for(int i=0;i<m+1;++i){
    // deb(sp);
    sp = max(ips[i+1] - ips[i],sp);
   }
   // deb(sp);
   if(sp>=t) cout << "Y" << endl;
   else cout << "N" << endl;
}

int main(){

    JAI SHREE RAM


    int TC = 1;
    //cin >> TC;
    for(int i=0;i<TC;++i){
    	//cout << "Case #" << i+1 << ": ";
    	solve();
    }
    return 0;
}


//	########  ##     ## 
//	##     ## ###   ### 
//	##     ## #### #### 
//	########  ## ### ## 
//	##        ##     ## 
//	##        ##     ## 
//	##        ##     ## 