class Solution {
private:
    long long num_nodes;
    long long sum=0;
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    vector<int> count;
    long long cnt=0;
    void run_dfs(int u)
    {
        visited[u]=true;
        cnt++;
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                run_dfs(i);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        num_nodes=n;
        visited.resize(n,false);
        count.resize(n,0);
        for(auto i:edges)
        {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                cnt=0;
                run_dfs(i);
                sum+=cnt*(num_nodes-cnt);
                num_nodes-=cnt;
            }
        }
        return sum;
    }
};