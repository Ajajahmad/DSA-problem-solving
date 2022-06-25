class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        long long sum =0;
        int n = nums.size();
        map<long long , int> mp;
        mp[0]++;
        for(int i=0;i<n;i++)
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