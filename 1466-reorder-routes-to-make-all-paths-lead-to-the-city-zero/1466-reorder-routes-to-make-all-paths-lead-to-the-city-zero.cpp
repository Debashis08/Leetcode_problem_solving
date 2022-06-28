class Solution {
private:
    int res=0;
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    void run_bfs(int u)
    {
        visited[u]=true;
        queue<int> q;
        q.push(u);
        while(q.empty()!=true)
        {
            int temp=q.front();
            q.pop();
            for(auto i:adjlist[temp])
            {
                if(visited[abs(i)]==false)
                {
                    visited[abs(i)]=true;
                    if(i>0)
                    {
                        res++;
                    }
                    q.push(abs(i));
                }
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        visited.resize(n,false);
        for(auto i:connections)
        {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(-i[0]);
        }
        run_bfs(0);
        return res;
    }
};