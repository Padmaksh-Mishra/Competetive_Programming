class Solution {
    
public:
    int path[2010][2010] = {{0}};
    int R,C;

    void dfs(int r,int c,vector<vector<int>>& graph){
        //vector<vector<int>> graph = *grph;
        if(r>=R||r<0||c>=C||c<0) return;
        if(path[r][c]>0) return;
        // if(r+1<R+1){
        //     dfs(r+1,c,graph);
        //     if(graph[r+1][c]>graph[r][c]) path[r][c] = max(path[r][c],1+path[r+1][c]);
        // }

        // if(c-1>=0){
        //     dfs(r,c-1,graph);
        //     if(graph[r][c-1]>graph[r][c]) path[r][c] = max(path[r][c],1+path[r][c-1]);
        // }

        if(r-1>=0){
            dfs(r-1,c,graph);
            if(graph[r-1][c]>graph[r][c]) path[r][c] = max(path[r][c],1+path[r-1][c]);
        }

        if(c+1<C){
            dfs(r,c+1,graph);    
            if(graph[r][c+1]>graph[r][c]) path[r][c] = max(path[r][c],1+path[r][c+1]);   
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans=0;
        R=matrix.size();
        C=matrix[0].size();
        // for(int i=0;i<R;i++){
        //     for(int k=0;k<C;k++){
        //         if(path[i][k]==0) dfs(i,k,matrix);        
        //         ans = max(ans,path[i][k]);
        //     }
        // }
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                ans=max(ans, 1+dfs(matrix, i, j));
        return ans;
    }
};