//Coding_Duck <-> PM <-> REDACTED <-> Blood_Reaper

# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
# define deb(x) cout << #x << " = " << x << endl

const ll MOD = 1e9 +7;
using namespace std;

int bexpo(int n,int p);

void dfs(vector<vector<int>> &graph,vector<int> &color,int parent){
	if(color[parent]!=-1) return;
	map<int,int> m;
	for(auto child : graph[parent]){
		m[color[child]]++;
	}
	for(int i=1;i<=4;++i){
		if(m[i]==0){
			color[parent] = i;
			break;
		}
	}
}
void solve(){
	int n,m; cin >> n >> m;
	vector<vector<int>> graph(n+1);
	vector<int> color(n+1,-1);
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i=0;i<n;i++){
		dfs(graph,color,i+1);
	}
	
	for(int i=1;i<=n;++i) cout << color[i] << " ";
	cout << endl;

}

int main(){

//for I/O----------------------------------

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif

//I/O end ---------------------------------

    int TC = 1;
    //cin >> TC;
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