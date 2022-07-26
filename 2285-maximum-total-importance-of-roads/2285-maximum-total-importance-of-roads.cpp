class Solution {
private:
    vector<long long> degree;
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        degree.resize(n,0);
        
        for(auto i:roads)
        {
            degree[i[0]]++;
            degree[i[1]]++;
        }
        long long res=0;
        sort(degree.begin(),degree.end(),greater());
        for(int i=0;i<degree.size();i++)
        {
            res+=n*degree[i];
            n--;
        }
        return res;
    }
};