class Solution{
public:
    int color[2001];
    vector<int> Adj[2001];
    bool IsVisited[2001];
    bool bfs(int i)
    {
        if(color[i] == -1)color[i] = 0;
        queue<int> q1;
        q1.push(i);
        while(!q1.empty())
        {
            int a = q1.front();
            q1.pop();
            int col = color[a];
            for(auto x : Adj[a])
            {
                if(color[x] == col)return false;
                if(IsVisited[x])continue;
                color[x] = 1 xor col;
                q1.push(x);
                IsVisited[x] = true;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i = 0 ; i <= 2000 ; i++){color[i] = -1;IsVisited[i]=false;}
        for(auto x : dislikes)
        {
            Adj[x[0]].push_back(x[1]);
            Adj[x[1]].push_back(x[0]);
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(!IsVisited[i])
            {
                IsVisited[i] = true;
                if(!bfs(i))return false;
            }
        }
        return true;
    }
};