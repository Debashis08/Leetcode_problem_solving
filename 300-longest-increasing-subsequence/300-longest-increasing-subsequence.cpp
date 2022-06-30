class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(),1);
        
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && lis[j]+1>lis[i])
                {
                    lis[i]=lis[j]+1;
                }
            }
        }
        return *max_element(lis.begin(),lis.end());
    }
};