class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int low,high;
        double sum=0;
        double res=INT_MIN;
        int count=0;
        for(low=0,high=0;high<nums.size();high++)
        {
            sum+=nums[high];
            count++;
            while(low<=high && count>k)
            {
                sum-=nums[low];
                low++;
                count--;
            }
            if(count==k)
            {
                res=max(res,sum);
            }

        }
                
        return (res/double(k));
    }
};