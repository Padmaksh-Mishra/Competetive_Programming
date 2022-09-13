# include <bits/stdc++.h>
# define JAI ios_base::sync_with_stdio(false); 
# define SHREE cin.tie(NULL); 
# define RAM cout.tie(NULL);
# define ll long long
//# define int ll
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl
# define pb push_back
# define f first
# define s second
# define NO cout << "No" << endl
# define YES cout << "Yes" << endl
# define sor(x) sort(begin(x), end(x))
# define siz(x) (ll)(x).size()
# define vi vector<int>
# define vll vector<ll>
# define all(x) (x).begin(), (x).end()

using namespace std;
const ll MOD = 1e9 +7;

void solve(){
	int n,m; cin >> n >> m;
	map<int,ll> ma,mb;
	for(int i=0;i<n;++i){
		int tmp; cin >> tmp;
		double t = log(tmp)/log(m);
		deb(t);
		if(t==(int)t) ma[1]+=tmp;
		else if(tmp%m==0) ma[tmp/(m*(int)t)]+=(m*(int)t);
		else ma[tmp] += 1;
	}
	int k; cin >> k;
	for(int i=0;i<k;++i){
		int tmp; cin >> tmp;
		double t = log(tmp)/log(m);
		deb(t);
		if(t==(int)t) mb[1]+=tmp;
		else if(tmp%m==0) mb[tmp/(m*(int)t)]+=(m*(int)t);
		else mb[tmp] += 1;
	}
	if(ma==mb){
		YES;
	}else NO;
}

int main(){

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