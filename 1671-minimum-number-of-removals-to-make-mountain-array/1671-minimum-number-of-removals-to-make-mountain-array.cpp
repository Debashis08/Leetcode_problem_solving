class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis(nums.size(),1);
        vector<int> lds(nums.size(),1);
        
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && lis[j]+1>lis[i])
                {
                    lis[i]=lis[j]+1;
                }
            }
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            for(int j=nums.size()-1;j>i;j--)
            {
                if(nums[j]<nums[i] && lds[j]+1>lds[i])
                {
                    lds[i]=lds[j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(lis[i]>1 && lds[i]>1)
            {
                ans=max(ans,lis[i]+lds[i]-1);
            }
        }
        cout<<ans<<endl;
        return (nums.size()-ans);
    }
};