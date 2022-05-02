class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=n-1;
        while(i<=j)
        {
            if(nums[i]%2!=0 && nums[j]%2==0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            if(nums[i]%2==0)
                i++;
            if(nums[j]%2!=0)
                j--;
        }
        return nums;
    }
};