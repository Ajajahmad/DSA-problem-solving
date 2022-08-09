class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0;
        int n = nums.size();
        int pro = 1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0) zero++;
            if(nums[i]!=0) pro = pro*nums[i];
        }
        for(int i =0;i<n;i++)
        {
            if(zero>1 ) nums[i]=0;
            else if(zero==0 ) nums[i] = pro/nums[i];
            else if(zero==1 && nums[i]==0) nums[i] = pro;
            else if(zero==1 && nums[i]!=0) nums[i] = 0; 
        }
        return nums;
    }
};