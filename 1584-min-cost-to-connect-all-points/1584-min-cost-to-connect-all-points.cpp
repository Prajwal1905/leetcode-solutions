class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<bool>visited(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int totalCost=0;
        int edgeUsed=0;
        while(!pq.empty() && edgeUsed<n){
            int cost=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node]=true;
            totalCost+=cost;
            edgeUsed++;
            for(int next=0;next<n;next++){
                if(!visited[next]){
                    int newCost=abs(points[node][0]-points[next][0])+
                                abs(points[node][1]-points[next][1]);
                    pq.push({newCost,next});
                }
            }
        }
        return totalCost;
        
    }
};