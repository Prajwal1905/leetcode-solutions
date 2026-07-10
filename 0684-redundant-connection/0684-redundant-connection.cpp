class Solution {
public:
    vector<int>parent;
    vector<int>rankValue;
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionNodes(int u,int v){
        int rootU=findParent(u);
        int rootV=findParent(v);
        if(rankValue[rootU]<rankValue[rootV]){
            parent[rootU]=rootV;
        }else if(rankValue[rootU]>rankValue[rootV]){
            parent[rootV]=rootU;
        }else{
            parent[rootV]=rootU;
            rankValue[rootU]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rankValue.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(findParent(u)==findParent(v)){
                return {u,v};
            }
            unionNodes(u,v);
        }
        return {};
    }
};