# include <bits/stdc++.h>

using namespace std;
const int N = 1e5;

int subtreeSum[N];
int evens[N];

void dfsTree(int vertex , int parent=0){

	subtreeSum[vertex] += vertex;
	if(vertex&1==0) evens[vertex]++;
	for(auto child : tree[vertex]){

		if(child==parent) continue;
		dfsTree(child);
		subtreeSum[vertex] +=subtreeSum[child];
		evens[vertex] += evens[child];
	}
}

int main(){

}