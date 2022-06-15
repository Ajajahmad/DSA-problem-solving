class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n , 1);
        int mx=1;
        for(int i=0;i<n;i++)
        {
            for(int pre = 0;pre<i;pre++)
            {
                if(nums[i]>nums[pre])
                    dp[i] = max(dp[i] ,1+dp[pre]);
                mx = max(dp[i], mx);
            }
        }
        return mx;
    }
};