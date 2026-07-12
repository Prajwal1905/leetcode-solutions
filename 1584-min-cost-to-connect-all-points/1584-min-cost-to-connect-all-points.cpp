class Solution {
public:
    vector<int>parent;
    vector<int>rankValue;
    struct Edge{
        int u,v,weight;
    };
    static bool compare(Edge a,Edge b){
        return a.weight<b.weight;
    }
    
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
        }else if(rankValue[rootU]<rankValue[rootV]){
            parent[rootV]=rootU;
        }else{
            parent[rootV]=rootU;
            rankValue[rootU]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        rankValue.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<Edge>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cost=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({i,j,cost});
            }
        }
        sort(edges.begin(),edges.end(),compare);
        int ans=0;
        for(auto edge:edges){
            if(findParent(edge.u)!=findParent(edge.v)){
                ans+=edge.weight;
                unionNodes(edge.u,edge.v);
            }

        }
        return ans;

    }
};