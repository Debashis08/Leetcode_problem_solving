class Solution 
{
private:
    map<int,vector<pair<int,int>>> adjlist;
    vector<int> distance;
    queue<tuple<int,int,int>> q_obj;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        distance.resize(n,INT_MAX);
        for(auto i: flights)
        {
            adjlist[i[0]].push_back({i[1],i[2]});
        }
        distance[src]=0;
        
        q_obj.push({0,src,0}); //distance,vertex,city in between
        while(q_obj.empty()!=true)
        {
            auto [d,u,s]=q_obj.front();
            q_obj.pop();
            for(auto i:adjlist[u])
            {
                int v=i.first;
                int w=i.second;
                if(distance[v]>d+w && s<=k)
                {
                    distance[v]=d+w;
                    q_obj.push({distance[v],v,s+1});
                }
            }
        }
        if(distance[dst]==INT_MAX)
        {
            return -1;
        }
        return distance[dst];
    }
};