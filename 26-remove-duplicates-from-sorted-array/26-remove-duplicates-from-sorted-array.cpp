class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        if(n==1) return 1;
        int i =1 , j=1;
        int pre = nums[0];
        while(j<n)
        {
            if(pre!=nums[j])
            {
                nums[i] = nums[j];
                pre = nums[i];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return i;
    }
};