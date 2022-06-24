class Solution 
{
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        visited.resize(rooms.size(),false);
        for(int i=0;i<rooms.size();i++)
        {
            for(auto j:rooms[i])
            {
                adjlist[i].push_back(j);
            }
        }
        dfs(0);
        for(auto i:visited)
        {
            if(i==false)
            {
                return false;
            }
        }
        return true;
    }
};