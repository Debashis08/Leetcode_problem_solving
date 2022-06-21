class Solution 
{
private:
    map<int,vector<int>> adjlist;
    vector<vector<int>> res;
    vector<int> curr_path;
    vector<bool> visited;
    void dfs_visit(int u,int destination)
    {
        visited[u]=true;
        if(u==destination)
        {
            res.push_back(curr_path);
            return;
        }
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                curr_path.push_back(i);
                dfs_visit(i,destination);
            }
            visited[i]=false;
            curr_path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        visited.resize(graph.size(),false);
        for(int i=0;i<graph.size();i++)
        {
            for(auto j:graph[i])
            {
                adjlist[i].push_back(j);
            }
        }
        curr_path.push_back(0);
        dfs_visit(0,graph.size()-1);
        return res;
    }
};