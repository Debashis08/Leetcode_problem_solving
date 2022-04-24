class Solution 
{
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        vector<int> edge_count;
        for(int i=0;i<edges.size()+2;i++)
        {
            edge_count.push_back(0);
        }
        for(int i=0;i<edges.size();i++)
        {
            edge_count[edges[i][0]]++;
            edge_count[edges[i][1]]++;
        }
        for(int i=0;i<edge_count.size();i++)
        {
            if(edge_count[i]==edges.size())
            {
                return i;
            }
        }
        return 0;
    }
};