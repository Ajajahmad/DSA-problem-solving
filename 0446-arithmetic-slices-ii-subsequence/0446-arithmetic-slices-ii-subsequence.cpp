class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<unordered_map<int,int>> dp(n+1);
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if((long(nums[i])-long(nums[j]))>INT_MAX || ( long(nums[i])-long(nums[j]))<INT_MIN ) continue;
                long dif = long(nums[i])-long(nums[j]);
                
                res += dp[j][dif];
                
                dp[i][dif] += dp[j][dif];
                dp[i][dif]+=1;
            }
            
        }
        return res;
    }
};