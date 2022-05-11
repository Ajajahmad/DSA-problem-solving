class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp (5,1);
        while(--n)
        {
            for(int i=3;i>=0;i--)
            {
                dp[i] += dp[i+1];
            }
        }
        int ans= 0;
        for(auto x:dp) ans+=x;
        return ans;
    }
};