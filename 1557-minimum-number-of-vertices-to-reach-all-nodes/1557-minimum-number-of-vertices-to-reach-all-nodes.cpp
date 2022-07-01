class Solution {
    vector<int> indegree;
    vector<int> res;
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        indegree.resize(n,0);
        for(auto i:edges)
        {
            indegree[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};