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
        if(rootU==rootV){
            return ;
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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rankValue.resize(26,0);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(string eqn:equations){
            if(eqn[1]=='='){
            int u=eqn[0]-'a';
            int v=eqn[3]-'a';

            unionNodes(u,v);
            }
        }

        for(string eqn:equations){
            if(eqn[1]=='!'){
            int u=eqn[0]-'a';
            int v=eqn[3]-'a';
            if(findParent(u)==findParent(v)){
                return false;
            }
        }
        }

        return true;
    }
};