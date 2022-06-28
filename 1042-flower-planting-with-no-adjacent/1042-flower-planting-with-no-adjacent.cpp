class Solution {
private:
    map<int,vector<int>> adjlist;
    vector<bool> visited;
    vector<int> flower;
    void run_bfs(int u)
    {
        queue<pair<int,int>> q;
        q.push({u,1});
        flower[u]=1;
        while(q.empty()!=true)
        {
            int temp=q.front().first;
            int flw=q.front().second;
            q.pop();
            for(auto i:adjlist[temp])
            {
                if(flower[i]==-1 || flower[i]==flower[temp])
                {
                    flw++;
                    flower[i]=flw;
                    if(flw>=4)
                    {
                        flw=flw%4;
                    }
                    q.push({i,flw});
                }
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        flower.resize(n+1,-1);
        for(auto i:paths)
        {
            adjlist[i[0]].push_back(i[1]);
            adjlist[i[1]].push_back(i[0]);
        }
        
        for(int i=1;i<n+1;i++)
        {
            if(flower[i]==-1)
            {
                run_bfs(i);
            }
        }
        flower.erase(flower.begin());
        return flower;
    }
};