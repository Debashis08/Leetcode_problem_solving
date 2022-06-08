class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<int> res;
        if(n==0)
        {
            return res;
        }
        if(n==1)
        {
            res.push_back(0);
            return res;
        }
        
        vector<vector<int>> adjlist(n);
        vector<int> indegree(n,0);
        queue<int> q;
        
        for(int i=0;i<edges.size();i++)
        {
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1)
            {
                q.push(i);
            }
        }
        while(q.empty()!=true)
        {
            res.clear();
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int temp=q.front();
                res.push_back(temp);
                q.pop();
                for(auto ite:adjlist[temp])
                {
                    indegree[ite]--;
                    if(indegree[ite]==1)
                    {
                        q.push(ite);
                    }
                }
            }
        }
        return res;
    }
};