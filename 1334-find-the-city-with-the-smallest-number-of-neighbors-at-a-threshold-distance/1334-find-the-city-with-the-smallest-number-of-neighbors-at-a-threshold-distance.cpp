class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    dist[i][j]=0;
                }
                else
                {
                    dist[i][j]=INT_MAX;
                }
            }
        }
        
        for(auto i:edges)
        {
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if((dist[i][k]!=INT_MAX && dist[j][k]!=INT_MAX) && (dist[i][j]>dist[i][k]+dist[k][j]))
                    {
                        dist[i][j]=dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int res=-1;
        int min_count=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=min_count)
            {
                min_count=count;
                res=i;
            }
        }
        return res;
    }
};