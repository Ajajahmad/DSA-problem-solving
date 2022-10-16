class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int sum =0 ,res=0;
        mp[0]++;
        for(int i=0;i<n;i++) 
        {
            if(nums[i]%2) sum++;
            if(mp.find(sum-k)!=mp.end()) res+= mp[sum-k];
            mp[sum]++;
        }
        
        return res;
    }
};