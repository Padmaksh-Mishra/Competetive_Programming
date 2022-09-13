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
pair<int,int> cows[N];
vi graph[N];
vi visited(N);
int mx,mix,my,miy;

void setIO(string name = "sublime");

void dfs(int v){
	if(visited[v]) return;
	visited[v]=1;
	mix = min(mix,cows[v].f);
	mx = max(mx,cows[v].f);
	miy = min(miy,cows[v].s);
	my = max(my,cows[v].s);
	for(auto child : graph[v]){
		dfs(child);
	}
}

void solve(){
	int n,m; cin >> n >> m;
	int x,y;
	for(int i=1;i<n+1;++i){
		cin >> x >> y;
		cows[i]={x,y};
	}
	for(int i=0;i<m;++i){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	int ans = MOD;
	for(int i=1;i<n;++i){
		if(!visited[i]){
			mx=-MOD,mix=MOD,my=-MOD,miy=MOD;
			dfs(i);
			ans = min(ans,((mx-mix+my-miy)<<1));
			//fill(visited.begin(), visited.end(),0);
		}
	}
	cout << ans << endl;
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