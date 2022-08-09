class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        int pre = -1000;
        while(i<n)
        {
            if(pre!=nums[i])
            {
                nums[j] = nums[i];
                pre = nums[j];
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return j;
    }
};