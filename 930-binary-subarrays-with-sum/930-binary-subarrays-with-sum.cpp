class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int sum=0;
        map<int,int> mp;
        mp[0]++;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
            {
                res += mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};