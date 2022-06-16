class Solution 
{
private:
    map<int,vector<int>> adjlist;
    vector<int> visited;
    vector<int> parent;
    // vector<int> res;
    bool dfs_find_cycle(int curr,int par)
    {
        visited[curr]=1;
        parent[curr]=par;
        for(auto i: adjlist[curr])
        {
            if(visited[i]==false)
            {
                if(dfs_find_cycle(i,curr)==true)
                {
                    return true;
                }
            }
            else if(i!=par)
            {
                // res.push_back(i);
                // res.push_back(curr);
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        if(edges.empty()==true)
        {
            return {};
        }        
        parent.resize(edges.size()+1,-1);
        visited.resize(edges.size()+1,0);

        for(auto it:edges)
        {
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
            if(dfs_find_cycle(it[0],it[1])==true)
            {
                return it;
            }
            fill(visited.begin(),visited.end(),0);
        }
        return {};
    }
};