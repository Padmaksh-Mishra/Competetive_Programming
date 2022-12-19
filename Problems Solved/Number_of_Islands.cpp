# include <bits/stdc++.h>

using namespace std;

int visited[301][301];

void dfs(int i,int j,vector<vector<char>>& grid){
	int rows = grid.size();
    int coloms = grid[0].size();

    if(i>rows-1||j>coloms-1||i<0||j<0) return;
    if(visited[i][j]) return;
    if(grid[i][j]=='0') return;

    visited[i][j] = 1;

    dfs(i+1,j,grid);
    dfs(i-1,j,grid);
    dfs(i,j-1,grid);
    dfs(i,j+1,grid);
}

int numIslands(vector<vector<char>>& grid) {
	int islands = 0;
    int rows = grid.size();
    int coloms = grid[0].size();

    for(int i=0;i<rows;++i){
        for(int j = 0;j<coloms;++j){
            if(visited[i][j]!=1&&grid[i][j]=='1') {
                islands++;
                dfs(i,j,grid);
            }
        }
    }
    return islands;        
}