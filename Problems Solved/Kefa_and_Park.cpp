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

vi tree[100001];
vi visited(100001);
vi cat(100001);
ll cats,res,m;
vll store(100001);
void dfs(int node){	
	cout << node << " " << store[node] << endl;
	if(visited[node]||store[node]>m) return;
	
	visited[node]=1;

	if(siz(tree[node])==1&&visited[tree[node][0]]) {
		res++;
		deb(node);
	}
	for(auto child : tree[node]){
		if(cat[child]==0) cats = 0;
		cats+=cat[child];
		store[child] = max(cats,store[node]);
		dfs(child);
		cats-=cat[child];
	}
}


void solve(){
	int n; cin >> n >> m;

	for(int i=0;i<n;++i) cin >> cat[i];
	for(int i=1;i<n;++i){
		int a,b; cin >> a >> b;
		a--;b--;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	cats+=cat[0];
	store[0]+=cats;
	dfs(0);
	cout << res << endl;
}

int main(){

    JAI SHREE RAM

    setIO();	//Google and other non judges
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