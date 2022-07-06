class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=0)
        {
            return 0;
        }
        int low,high;
        int mul=1;
        int count=0;
        for(low=0,high=0;high<nums.size();high++)
        {
            mul*=nums[high];
            while(low<=high && mul>=k)
            {
                mul/=nums[low];
                low++;
            }
            count+=high-low+1;
        }
        return count;
    }
};