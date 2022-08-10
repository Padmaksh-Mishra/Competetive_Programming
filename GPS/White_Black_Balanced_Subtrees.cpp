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
vi balance(4001);
vi graph[4001];
string s;
void dfs(int vertex,int parent=0){

	if(s[vertex-1]=='W') balance[vertex]=1;
	else balance[vertex]=-1;
	for(auto child : graph[vertex]){

		if(child==parent) continue;
		dfs(child,vertex);
		balance[vertex]+=balance[child];
	}
}

void solve(){
	int n; cin >> n;
	cin >> s;
	for(int i=2;i<=n;++i){
		int parent; cin >> parent;
        graph[parent].pb(i);
        // graph[i].pb(parent);
	}
	dfs(1);
	int ans = 0;
	for(int i=1;i<=n;++i){
		if(balance[i]==0) ans++;
	}
	cout << ans << endl;
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