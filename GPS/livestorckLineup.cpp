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

map<string,vector<string>> graph; 
map<string,int> visited;
void setIO(string name = "sublime");

void dfs(string s){
	//deb(s);
	if(visited[s]) return;
	visited[s]=1;
	cout << s << endl;
	sor(graph[s]);
	for(auto next : graph[s]){
		// deb(next);
		dfs(next);
	}
}


void solve(){
	set<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"};
	// sor(cows);
	string s,tmp,b;
	int n; cin >> n;
	while(n--){
      	cin >> s;
      	for(int i=0;i<4;++i) cin >> tmp;
      	cin >> b;
      	//deb(b);
      	graph[b].pb(s);
	}
	for(auto cow : cows){
		if(!visited[cow]) dfs(cow);
		//deb(cow);
	}
}

int main(){

    JAI SHREE RAM

    setIO();	//Does not work with Google 	
    int TC = 1;
    //cin >> TC;
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