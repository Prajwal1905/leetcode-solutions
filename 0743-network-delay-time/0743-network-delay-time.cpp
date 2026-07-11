class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        vector<int>distance(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        distance[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto neighbor:adj[node]){
                int nextNode=neighbor.first;
                int weight=neighbor.second;
                if(dist+weight<distance[nextNode]){
                    distance[nextNode]=dist+weight;
                    pq.push({distance[nextNode],nextNode});

                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,distance[i]);
        }
        return ans;
    }
};