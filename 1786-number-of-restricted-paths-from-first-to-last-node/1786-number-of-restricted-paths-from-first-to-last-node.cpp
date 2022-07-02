class Solution {
private:
    int mod=1e9+7;
    map<int,vector<pair<int,int>>> adjlist;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> distance;
    vector<int> dp;
    void relax(int u,int v,int w)
    {
        if(distance[v]>distance[u]+w)
        {
            distance[v]=distance[u]+w;
            pq.push({distance[v],v});
        }
    }
    int dfs(int u,int n)
    {
        if(u==n)
        {
            return 1;
        }
        if(dp[u]!=-1)
        {
            return dp[u];
        }
        int ans=0;
        for(auto i:adjlist[u])
        {
            if(distance[u]>distance[i.first])
            {
                ans=(ans%mod + (dfs(i.first,n))%mod)%mod;
            }
        }
        dp[u]=ans%mod;
        return dp[u];
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        distance.resize(n+1,INT_MAX);
        dp.resize(n+1,-1);
        for(auto i:edges)
        {
            adjlist[i[0]].push_back({i[1],i[2]});
            adjlist[i[1]].push_back({i[0],i[2]});
        }
        pq.push({0,n});
        distance[n]=0;
        while(pq.empty()!=true)
        {
            pair<int,int> temp=pq.top();
            pq.pop();
            for(auto i:adjlist[temp.second])
            {
                relax(temp.second,i.first,i.second);
            }
        }
        int res=dfs(1,n)%mod;
        return res;
    }
};