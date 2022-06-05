class Solution 
{
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        if(source==destination)
        {
            return true;
        }
        vector<int> visited(n,0);
        vector<vector<int>> adjlist(n);
        for(auto ite:edges)
        {
            adjlist[ite[0]].push_back(ite[1]);
            adjlist[ite[1]].push_back(ite[0]);
        }
        queue<int> q;
        q.push(source);
        while(q.empty()!=true)
        {
            int temp=q.front();
            q.pop();
            visited[temp]=1;
            for(auto ite:adjlist[temp])
            {
                if(ite==destination)
                {
                    return true;
                }
                if(visited[ite]==0)
                {
                    q.push(ite);
                }
            }
        }
        return false;
    }
};