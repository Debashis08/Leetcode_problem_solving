class Solution {
private:
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    vector<vector<int>> res;
    void dfs_visit(int u,int source)
    {
        visited[u]=true;
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                dfs_visit(i,source);
                res[i].push_back(source);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        visited.resize(n,false);
        res.resize(n);
        for(auto i:edges)
        {
            adjlist[i[0]].push_back(i[1]);
        }
        for(int i=0;i<n;i++)
        {
            fill(visited.begin(),visited.end(),false);
            dfs_visit(i,i);
        }
        return res;
    }
};