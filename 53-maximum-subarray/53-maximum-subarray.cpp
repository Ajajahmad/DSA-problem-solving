class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum = nums[0] ; 
        int sum = 0;
        if(nums[0] >0) sum = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i];
            msum = max(msum , sum);
            if(sum<0) sum=0;
        }
        return msum;
    }
};