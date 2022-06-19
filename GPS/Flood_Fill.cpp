# include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int visited[N];

void dfs(int i,int j,int oldColor ,int newColor ,vector<vector<int>>& image){

	int rows = image.size();
	int colomns = image[0].size();
	if(i<0||j<0||i>rows-1||j>colomns-1) return;
	if(image[i][j]!=oldColor) return;
	image[i][j] = newColor;
	dfs(i,j+1,oldColor,newColor,image);
	dfs(i+1,j,oldColor,newColor,image);
	dfs(i,j-1,oldColor,newColor,image);
	dfs(i-1,j,oldColor,newColor,image);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	if(newColor!=image[i][j])
		dfs(sr,sc,image[sr][sc],newColor,image);
	return image;
}


// not needed in leetcode

int main(){
	
}