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
vi hsh(200001);
int n,m;
bool isPossible(int t){
	int tasks_done = 0;
	for(int i=1;i<=n;++i){
		tasks_done += min(t,hsh[i]) + (t-min(t,hsh[i]))/2;
	}
	if(tasks_done>=m) return true;
	else return false;
}
void reset(){
	for(int i=1;i<=n;++i) hsh[i]=0;
}
void solve(){
	cin >> n >> m;
	reset();
	int tmp;
	for(int i=0;i<m;++i){
		cin >> tmp;
		hsh[tmp]++;
	}
	int ans = MOD;
	int end = (m<<1);
	int begin = 1;
	int mid;
	while(end-begin > 1){
		mid = ((begin+end)>>1);
		//deb(mid);
		if(isPossible(mid)){
			end = mid;
		}else begin = mid+1;
	}
	if(isPossible(begin)) ans = begin;
	else if(isPossible(mid)) ans = mid;
	else ans = end;
	cout << ans << endl;
}

signed main(){

    JAI SHREE RAM


    int TC = 1;
    cin >> TC;
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