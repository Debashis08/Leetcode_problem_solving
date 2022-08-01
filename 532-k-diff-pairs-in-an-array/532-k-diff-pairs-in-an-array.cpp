class Solution {
private:
    vector<int> vec;
    map<int,int> m;
public:
    int findPairs(vector<int>& nums, int k) {
        for(auto i:nums)
        {
            m[i]++;
        }
        int sum=0;
        for(auto i:m)
        {
            vec.push_back(i.first);
            if(i.second>1)
            {
                sum++;
            }
        }
        if(k==0)
        {
            return sum;
        }
        int i=0,j=1;
        int res=0;
        while(j<vec.size())
        {
            if(vec[j]-vec[i]<k)
            {
                j++;
            }
            else if(vec[j]-vec[i]>k)
            {
                i++;
            }
            else
            {
                i++;
                j++;
                res++;
            }
        }
        return res;
    }
};