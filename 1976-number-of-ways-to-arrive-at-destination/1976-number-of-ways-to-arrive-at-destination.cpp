#define lli long long int
lli mod=1e9+7;

class Solution {
    map<lli,vector<pair<lli,lli>>> adjlist;
    vector<lli> distance;
    vector<lli> dp;
    priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> pq;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        distance.resize(n,LONG_MAX);
        dp.resize(n,-1);
        for(auto i:roads)
        {
            adjlist[i[0]].push_back({i[1],i[2]});
            adjlist[i[1]].push_back({i[0],i[2]});
        }
        pq.push({0,0}); //distance,node_val
        distance[0]=0;
        dp[0]=1;
        while(pq.empty()!=true)
        {
            // pair<lli,lli> temp=pq.top();
            // pq.pop();
            // for(auto i:adjlist[temp.second])
            // {
            //     if(distance[i.first]>distance[temp.second]+i.second)
            //     {
            //         distance[i.first]=distance[temp.second]+i.second;
            //         dp[i.first]=dp[temp.second]%mod;
            //         pq.push({distance[i.first],i.first});
            //     }
            //     else if(distance[i.first]==distance[temp.second]+i.second)
            //     {
            //         dp[i.first]=(dp[i.first]%mod + dp[temp.second]%mod)%mod;
            //     }
            // }
            pair<lli,lli> ele=pq.top();
            pq.pop();
            lli last_dis=ele.first;
            lli last_node=ele.second;
            for(auto pr:adjlist[last_node])
            {
                lli dest=pr.first;
                lli time=pr.second;
                if(last_dis+time<distance[dest])
                {
                    distance[dest]=last_dis+time;
                    dp[dest]=dp[last_node]%mod;
                    pq.push({last_dis+time,dest});
                }
                else if(distance[dest]==time+last_dis)
                {
                    dp[dest]=(dp[dest]%mod + dp[last_node]%mod)%mod;
                }
            }
        }
        return dp[n-1];
    }
};