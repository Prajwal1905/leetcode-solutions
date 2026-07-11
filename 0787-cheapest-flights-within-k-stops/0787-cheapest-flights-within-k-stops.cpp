class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto flight:flights){
            int u=flight[0];
            int v=flight[1];
            int cost=flight[2];
            adj[u].push_back({v,cost});

        }
        vector<int>distance(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        distance[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto neighbor:adj[node]){
                int nextNode=neighbor.first;
                int edgeCost=neighbor.second;
                if(cost+edgeCost<distance[nextNode]){
                    distance[nextNode]=cost+edgeCost;
                    q.push({stops+1,{nextNode,distance[nextNode]}});
                }
            }
        }
        if(distance[dst]==INT_MAX){
            return -1;

        }
        return distance[dst];
    }
};