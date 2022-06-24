class Solution {
private:
    int n;
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    void run_dfs(int u)
    {
        visited[u]=true;
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                run_dfs(i);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        n=stones.size();
        visited.resize(n,false);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                run_dfs(i);
                count++;
            }
        }
        return (n-count);
    }
};