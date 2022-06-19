# include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
vector<int> graph[N];
int visited[N];

void dfs(int vertex){
	/* vertex me ane ke baad 
		child dekhne ke pehele 
		jo karna hai karo */

	visited[vertex] = 1;
	for(auto child : graph[vertex]){
		/* child ke upr dfs lagane
			se pehele jo karna hai yahi karo */

		if(visited[child]) continue;
		
		dfs(child);

		/* child se bahar ane ke baad 
			jo karna hai idhar karo */
	}
	/* vertex ko chodne se pehele 
		jo karna hai kar lo */

}

int main(){
	int v,e; cin >> v >> e;
	for(int i=0;i<e;i++){
		int v1,v2; cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int cc=0;
	for(int i=1;i<v+1;++i){
		if(visited[i]) continue;
		dfs(i);
		cc++;
	}

	cout << cc;
}