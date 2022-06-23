class Solution {
private:
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    vector<int> color;
    queue<int> q;
    bool bfs_color_graph(int u)
    {
        if(color[u]==0)
        {
            color[u]=1;
        }
        q.push(u);
        while(q.empty()!=true)
        {
            int temp=q.front();
            q.pop();
            int cur_col=color[temp];
            for(auto i:adjlist[temp])
            {
                if(color[i]==cur_col)
                {
                    return false;
                }
                if(visited[i])
                {
                    continue;
                }
                if(cur_col==1)
                {
                    color[i]=2;
                }
                else
                {
                    color[i]=1;
                }
                    visited[i]=true;
                    q.push(i);
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        visited.resize(n+1,false);
        color.resize(n+1,0);
        for(auto i:dislikes)
        {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                if(bfs_color_graph(i)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};