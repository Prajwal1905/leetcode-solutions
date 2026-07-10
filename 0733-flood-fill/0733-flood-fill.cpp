class Solution {
public:
    void dfs( int row, int col,vector<vector<int>>& image,int originalColor, int newColor){
        image[row][col]=newColor;
        int n=image.size();
        int m=image[0].size();
        int dRow[]={-1,0,1,0};
        int dCol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newRow=row+dRow[i];
            int newCol=col+dCol[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && image[newRow][newCol]==originalColor){
                dfs(newRow,newCol,image,originalColor,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor==color){
            return image;
        }
        dfs(sr,sc,image,originalColor,color);
        return image;
    }
};