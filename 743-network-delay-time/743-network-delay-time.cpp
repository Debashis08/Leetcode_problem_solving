class Solution 
{
private:
    int source;
    map<int,vector<pair<int,int>>> adjlist;
    vector<int> distance;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq_obj;
    
    void relax(int u,int v,int w)
    {
        if(distance[v]>distance[u]+w)
        {
            distance[v]=distance[u]+w;
            pq_obj.push({distance[v],v});
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        source=k;
        distance.resize(n+1,INT_MAX);
        for(auto i: times)
        {
            adjlist[i[0]].push_back({i[1],i[2]});
        }
        distance[source]=0;
        pq_obj.push({0,source});
        while(pq_obj.empty()!=true)
        {
            pair<int,int> temp=pq_obj.top();
            pq_obj.pop();
            int u=temp.second;
            for(auto i:adjlist[u])
            {
                pair<int,int> x=i;
                int v=x.first;
                int w=x.second;
                relax(u,v,w);
            }
        }
        int res=*max_element(distance.begin()+1,distance.end());
        if(res==INT_MAX)
        {
            return -1;
        }
        return res;
    }
};