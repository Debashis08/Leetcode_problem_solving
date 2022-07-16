class Solution {
private:
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    void dfs(int u)
    {
        visited[u]=true;
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                dfs(i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        visited.resize(n,false);
        for(auto i:connections)
        {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                dfs(i);
                count++;
            }
        }
        return (count-1);
    }
};