class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int xr = 0 ;
        for(auto num:nums)
            xr ^= num;
        return xr;
    } 
};