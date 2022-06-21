class Solution {
    
public:
    
    vector<vector<pair<int,int>>> graph;
    vector<int> dis;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        graph.resize(n);
        dis.resize(n,INT_MAX);
        
        for(int i = 0 ; i<flights.size() ; i++){
            
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            
            graph[u].push_back({v,w});
        }
        
        queue<tuple<int,int,int>> pq;
        pq.push({0, src , 0});      //  dis , source , no of stops
         
        dis[src] = 0;
        
        while(!pq.empty()){
            
            auto [d,u,st] = pq.front();
            pq.pop();
            
            
            for(auto [v , w] : graph[u]){
                
                if(d + w < dis[v]  && st<=k){
            
                    dis[v] = d + w;
                    
                    pq.push({dis[v], v, st+1});
                }
                
            }
        }
        
        if(dis[dst]==INT_MAX)return -1;
        
        return dis[dst];
        
    }
    
   
    
};