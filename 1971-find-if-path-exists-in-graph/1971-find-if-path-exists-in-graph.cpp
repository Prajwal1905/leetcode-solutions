class Solution {
public:
    bool dfs(int node,int dest,vector<vector<int>>&adj,vector<bool>&visited){
        visited[node]=true;
        if(node==dest){
            return true;
        }
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,dest,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return dfs(src,dest,adj,visited);
    }
};