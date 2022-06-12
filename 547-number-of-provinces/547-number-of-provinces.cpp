class Solution 
{
private:
    vector<int> visited;
    vector<vector<int>> graph;
    int no_of_provinces=0;
    void dfs_visit(int u)
    {
        visited[u]=1;
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==0 && graph[u][i]==1)
            {
                dfs_visit(i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        graph=isConnected;
        visited.resize(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            visited[i]=0;
        }
        for(int i=0;i<graph.size();i++)
        {
            if(visited[i]==0)
            {
                dfs_visit(i);
                no_of_provinces++;
            }
        }
        return no_of_provinces;
    }
};