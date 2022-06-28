class Solution {
private:
    int n;
    map<int,vector<int>> adjlist;
    vector<bool> res;
    bool run_bfs(int src,int dst)
    {
        vector<bool> visited(n,false);
        visited[src]=true;
        queue<int> q;
        q.push(src);
        while(q.empty()!=true)
        {
            int temp=q.front();
            q.pop();
            for(auto i:adjlist[temp])
            {
                if(i==dst)
                {
                    return true;
                }
                if(visited[i]==false)
                {
                    q.push(i);
                    visited[i]=true;
                }
                
            }
        }
        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        n=numCourses;        
        for(auto i:prerequisites)
        {
            adjlist[i[0]].push_back(i[1]);
        }
        for(auto i=0;i<queries.size();i++)
        {
            vector<int> temp=queries[i];
            if(run_bfs(temp[0],temp[1])==true)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;
    }
};