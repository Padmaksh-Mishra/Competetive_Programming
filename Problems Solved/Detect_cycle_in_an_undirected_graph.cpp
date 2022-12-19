# include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
vector<int> graph[N];
int visited[N];

bool dfs(int vertex,int parent){
	/* vertex me ane ke baad 
		child dekhne ke pehele 
		jo karna hai karo */
	bool loopExists = false;
	visited[vertex] = 1;
	for(auto child : graph[vertex]){
		/* child ke upr dfs lagane
			se pehele jo karna hai yahi karo */
		if(visited[child]&&(child==parent)) continue;
		if(visited[child]) return true;
		//cout << "Child = " << child << " " << "parent = " << vertex << endl;
		
		loopExists |= dfs(child,vertex);
		/* child se bahar ane ke baad 
			jo karna hai idhar karo */
	}
	/* vertex ko chodne se pehele 
		jo karna hai kar lo */
	return loopExists;
}

int main(){
	int v,e; cin >> v >> e;
	for(int i=0;i<e;i++){
		int v1,v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	bool loopExists = false;
	for(int i=1;i<v+1;++i){
		if(visited[i]) continue;
		loopExists|=dfs(i,0);
	}
	cout << loopExists ;
}