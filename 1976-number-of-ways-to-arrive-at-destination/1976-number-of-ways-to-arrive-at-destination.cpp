#define ll long long int
ll mod=1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        map<ll,vector<pair<ll,ll>>> mp;
        
        for(auto road:roads)
        {
            mp[road[0]].push_back({road[1],road[2]});
            mp[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dis(n,LONG_MAX);
        vector<ll> ways(n,0);
        pq.push({0,0});
        ways[0]=1;
        dis[0]=0;
        while(!pq.empty())
        {
            pair<ll,ll> ele=pq.top();
            pq.pop();
            ll last_dis=ele.first;
            ll last_node=ele.second;
            for(auto pr:mp[last_node])
            {
                ll dest=pr.first;
                ll time=pr.second;
                if(last_dis+time<dis[dest])
                {
                    dis[dest]=last_dis+time;
                    ways[dest]=ways[last_node]%mod;
                    pq.push({last_dis+time,dest});
                }
                else if(dis[dest]==time+last_dis)
                {
                    ways[dest]=(ways[dest]%mod + ways[last_node]%mod)%mod;
                }
            }
        }
        return ways[n-1];
    }
};