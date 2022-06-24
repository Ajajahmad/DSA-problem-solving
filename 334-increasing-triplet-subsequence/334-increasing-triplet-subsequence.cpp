class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mn1=INT_MAX, mn2=INT_MAX;
        int mn1i =0, mn2i=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<mn1)
            {
                mn1= nums[i];
                mn1i = i;
            }
            else if(nums[i]<mn2 && nums[i]>mn1 && i>mn1i){
                mn2 = nums[i];
                mn2i = i;
            }
            else if(nums[i] >mn2 && i>mn2i){
                return true;
            }
                
        }
        return false;
    }
};