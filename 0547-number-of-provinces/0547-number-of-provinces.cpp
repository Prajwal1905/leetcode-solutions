class Solution {
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<bool>&visited){
        visited[city]=true;
        int n=isConnected.size();
        for(int neighbor=0;neighbor<n;neighbor++){
            if(isConnected[city][neighbor]==1 && !visited[neighbor]){
                dfs(neighbor,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        for(int city=0;city<n;city++){
            if(!visited[city]){
                count++;
                dfs(city,isConnected,visited);
            }
        }
        return count;
    }
};