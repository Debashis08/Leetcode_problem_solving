class Solution 
{
private:
    vector<int> res;
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return res;
        }
        res.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            res.push_back(res[i-1]+nums[i]);
        }
        return res;
    }
};