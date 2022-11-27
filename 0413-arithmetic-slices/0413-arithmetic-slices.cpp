class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<unordered_map<int,long> >mp(n+1);
        for(int i=1;i<n;i++)
        {
            long dif = long(nums[i])-long(nums[i-1]);
            res += mp[i-1][dif];
            
            mp[i][dif] += mp[i-1][dif];
            mp[i][dif] += 1;
        }
        return res;
    }
};