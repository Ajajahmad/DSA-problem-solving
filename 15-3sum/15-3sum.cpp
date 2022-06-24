class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n  = nums.size();
        if(n<3) return {};
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        
        map<vector<int> , int> mp;
        for(int i=0;i<n-1;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            int l=i+1, r=n-1;
            while(l<r)
            {
                if(nums[i]+nums[l]+nums[r] == 0)
                {
                    mp[{nums[i] , nums[l] , nums[r]}]++ ;
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r] > 0)
                {
                    r--;
                }
                else
                    l++;
            }
        }
        for(auto it:mp)
        {
            res.push_back(it.first);
        }
        return res;
    }
};