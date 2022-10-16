class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int i =0, j=0;
        int res =0;
        while(j<n)
        {
            if(nums[j]-nums[i]<=k) j++;
            else
            {
                res++;
                i =j;
                j++;
            }
        }
        return res+1;
    }
};