class Solution {
private:
    map<int,vector<int>> adjlist;
    int count=0;
    vector<bool> visited;
    vector<int> vis_count;
    float calc_dist(long x1,long y1,long x2,long y2)
    {
        float d=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        return (sqrt(d));
    }
    void dfs(int u)
    {
        visited[u]=true;
        count++;
        for(auto i:adjlist[u])
        {
            if(visited[i]==false)
            {
                dfs(i);
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        visited.resize(bombs.size(),false);
        vis_count.resize(bombs.size(),0);
        for(int i=0;i<bombs.size();i++)
        {
            for(int j=0;j<bombs.size();j++)
            {
                if(i!=j)
                {
                    if(calc_dist(bombs[i][0],bombs[i][1],bombs[j][0],bombs[j][1])<=bombs[i][2])
                    {
                        adjlist[i].push_back(j);
                    }
                }
            }
        }
        
        for(int i=0;i<bombs.size();i++)
        {
            fill(visited.begin(),visited.end(),false);
            count=0;
            dfs(i);
            vis_count[i]=count;
        }
        return *max_element(vis_count.begin(),vis_count.end());
    }
};