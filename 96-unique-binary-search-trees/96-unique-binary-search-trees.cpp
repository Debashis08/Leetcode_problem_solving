class Solution 
{
private:
    int res=0;
    vector<int> vec;
public:
    int numTrees(int n) 
    {
        if(n<=1)
        {
            return 1;
        }
        vec.push_back(1);
        vec.push_back(1);
        for(int i=2;i<=n;i++)
        {
            vec.push_back(0);
            for(int j=0;j<i;j++)
            {
                vec[i]+=vec[j]*vec[i-j-1];
            }
        }
        return (*(vec.end()-1));
    }
};