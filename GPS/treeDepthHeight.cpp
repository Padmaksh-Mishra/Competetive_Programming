//Coding_Duck <-> PM <-> REDACTED

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
const int N = 1e5;
using namespace std;

int bexpo(int n,int p);
vector<int> graph[N];
int height[N],depth[N];
void treeDFS (int vertex,int parent=0){

	for(auto child : graph[vertex]){
		if(child==parent) continue;
		depth[child] = depth[vertex]+1;
		treeDFS(child,vertex);
		height[vertex] = max(height[vertex],height[child] + 1);
	}
	
}
void solve(){
	int v,e; cin >> v; e = v-1;
	for(int i=0;i<e;++i){
		int a,b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	treeDFS(1);
	for(int i = 0,i<v;++i){
		cout << height[i] << " " << depth[i] << endl;
	}    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); // useless since cout is not tied to anything

    int TC = 1;
    cin >> TC;
    while(TC--){
        solve();
    }
    return 0;
}


//Binary Exponention Iterative
int bexpo(int n,int p){ 
    int ans = 1,tmp = n;
    while(p>0){
        if(p&1) ans = (ans * 1LL * tmp)%MOD;
        tmp = (tmp * 1LL * tmp)%MOD;
        p>>=1;
    }
    return ans;
}
