class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int n  =nums.size();
        int sum = 0, res= 0;
        mp[0]++;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            if(mp.find(sum-goal)!=mp.end()) res+=mp[sum-goal];
            mp[sum]++;
        }
        return res;
    }
};