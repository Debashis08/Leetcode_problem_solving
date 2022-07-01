class Solution {
private:
    unordered_map<int,unordered_set<int>> graph;
    int res=0;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        for(auto i:roads)
        {
            graph[i[0]].insert(i[1]);
            graph[i[1]].insert(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x=graph[i].size();
                int y=graph[j].size();
                if(graph[i].find(j)!=graph[i].end())
                {
                    res=max(res,(x+y-1));
                }
                else
                {
                    res=max(res,(x+y));
                }
            }
        }
        return res;
    }
};