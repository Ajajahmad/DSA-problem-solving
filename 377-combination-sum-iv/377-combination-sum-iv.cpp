class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<uint> dp(target + 1); dp[0] = 1;
	// start filling the dp array from bottom, i.e curTarget = 1 till target.
	for (int curTarget = 1; curTarget <= target; curTarget++) 
        for (auto& num : nums)     // check for all elements from nums
            if (num <= curTarget)  // an element will only be taken if it is less than target to be achieved
                // the optimal answer(no. of combination) of remaining value is added to dp[curTarget]
				dp[curTarget] += dp[curTarget - num];   
    return dp[target];
    }
};