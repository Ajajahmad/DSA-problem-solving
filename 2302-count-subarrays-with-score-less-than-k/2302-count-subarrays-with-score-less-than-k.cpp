class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res=0,sum=0;
        for(int i=0,j=0;j<nums.size();j++)
        {
            sum+=nums[j];
            while(sum*(j-i+1)>=k)
                sum -= nums[i++];
            res += j-i+1;
        }
        return res;
    }
};