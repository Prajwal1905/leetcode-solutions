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
    void unionNode(int u,int v){
        int rootU=findParent(u);
        int rootV=findParent(v);
        if(rootU==rootV){
            return;
        }
        if(rankValue[rootU]<rankValue[rootV]){
            parent[rootU]=rootV;
        }else if(rankValue[rootU]>rankValue[rootV]){
            parent[rootV]=rootU;
        }else{
            parent[rootV]=rootU;
            rankValue[rootU]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;

        }
        parent.resize(n);
        rankValue.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto edge:connections){
            int u=edge[0];
            int v=edge[1];
            unionNode(u,v);
        }
        int components=0;
        for(int i=0;i<n;i++){
            if(findParent(i)==i){
                components++;
            }
        }
        return components-1;
    }
};