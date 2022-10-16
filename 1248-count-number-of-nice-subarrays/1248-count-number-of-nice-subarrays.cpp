class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++) 
        {
            if(nums[i]%2) nums[i]=1;
            else nums[i] = 0;
        }
        
        int res= 0;
        int sum =0 ;
        map<int , int> mp;
        mp[0]++;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()) res+=mp[sum-k];
            mp[sum]++;
        }
        return res;
    }
};