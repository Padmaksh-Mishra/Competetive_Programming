# include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> graph[2001];	//assuming the maxium number of vertices to be 2000
vector<bool> visited(2001);
vector<int> mother_vertex;	//vector to store all vertices from which we can reach all other points
const int INF = 1e9 + 9;

void reset(){
	for(int i=0;i<=n;++i){
		visited[i] = false;
	}
}
void dfs(int parent){
	if(visited[parent]) return;
	else visited[parent] = true;
	for(auto child : graph[parent]){
		dfs(child.first);
	}
}
void solve(){	
	int dp[n+1][n+1];
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			dp[i][j] = INF;
			if(i==j) dp[i][j] = 0;
		}
	}
	for(int i=0;i<m;++i){
		int a,b,c; cin >> a >> b >> c;
		graph[a].push_back(make_pair(b,c));	
		dp[a][b] = c;
	}
	for(int i=1;i<=n;++i){
		reset();
		dfs(i);
		bool ok = true;
		for(int j=1;j<=n;++j){
			if(!visited[j]){
				ok = false;
				break;
			}
		}
		if(ok){
			mother_vertex.push_back(i);
		}
	}
	if(mother_vertex.size()==0){
		cout << "No Potential Starting Point" << endl;
		return;
	}
	cout << "Potential Starting Points: ";
	for(auto val : mother_vertex) cout << val << " ";
	cout << endl;

	//FWA start--------------
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	//end------------------
	int ans = INF;
	vector<int> great;
	for(auto good : mother_vertex){
		int tmp = 0;
		for(int i=1;i<=n;++i){
			tmp = max(tmp,dp[good][i]);
		}
		ans = min(tmp,ans);
	}
	for(auto good : mother_vertex){
		int tmp = 0;
		for(int i=1;i<=n;++i){
			tmp = max(tmp,dp[good][i]);
		}
		if(tmp==ans) great.push_back(good);
	}
	cout << "Optimal Starting Points: ";
	for(auto val : great){
		cout << val << " ";
	}
	cout << endl;
	cout << "Optimal Time to touch all vertices: " << ans << endl;
}

int main(){
	cout << "Enter the number of vertices : ";
	cin >> n;
	cout << "Enter the number of edges : ";
	cin >> m;
	cout << "Enter each edge along with the time required to burn it :" << endl;

	solve();
	return 0;
}