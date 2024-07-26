class Solution {
    void dijsktra(int src,vector<vector<pair<int,int>>> &adj,vector<vector<int>> &dist){
        priority_queue<pair<int,int>> pq;
        dist[src][src]=0;
        pq.push({0,src});
        pair<int,int> crr;
        int d;
        while(!pq.empty()){
            crr= pq.top();
            pq.pop();
            for(auto &node:adj[crr.second]){
                if((-1*crr.first) + node.second<=dist[src][node.first]){
                    d= (-1*crr.first)+node.second;
                    dist[src][node.first]=d;
                    pq.push({-1*d,node.first});
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &edge:edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++){
            dijsktra(i,adj,dist);
        }
        int res=-1,count,minCount=INT_MAX;
        for(int i=0;i<n;i++){
            count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=distanceThreshold)count++;
            }
            if(count<=minCount){
                minCount=count;
                res=i;
            }
        }
        return res;
    }
};