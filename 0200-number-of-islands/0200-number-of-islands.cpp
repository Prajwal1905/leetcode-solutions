class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<bool>>&visited){
        visited[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+dRow[i];
            int newCol=col+dCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && grid[newRow][newCol]=='1' && !visited[newRow][newCol]){
                dfs(newRow,newCol,grid,visited);
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]=='1' && !visited[row][col]){
                    count++;
                    dfs(row,col,grid,visited);
                }
            }
        }
        return count;

    }
};