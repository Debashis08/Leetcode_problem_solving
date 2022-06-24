class Solution {
private:
    int n;
    map<int,vector<int>> adjlist;
    vector<int> quiet_obj;
    vector<bool> visited;
    vector<int> res;
    void run_bfs(int u,int q)
    {
        visited[u]=true;
        queue<int> q_obj;
        q_obj.push(u);
        while(q_obj.empty()!=true)
        {
            int temp=q_obj.front();
            q_obj.pop();
            for(auto i:adjlist[temp])
            {
                if(visited[i]==false)
                {
                    visited[i]=true;
                    if(quiet_obj[i]<q)
                    {
                        q=quiet_obj[i];
                        u=i;
                    }
                    q_obj.push(i);
                }
            }
        }
        res.push_back(u);
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        n=quiet.size();
        quiet_obj=quiet;
        visited.resize(n,false);
        for(auto i:richer)
        {
            adjlist[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            fill(visited.begin(),visited.end(),false);
            run_bfs(i,quiet_obj[i]);
        }
        return res;
    }
};