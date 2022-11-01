class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int sum =0;
        int n = nums.size();
        int i=0,j=0;
        int mn = INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=k){
                mn = min(mn, j-i+1);
                while(sum>=k)
                {
                    mn = min(mn , j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return (mn==INT_MAX)? 0 : mn;
    }
};