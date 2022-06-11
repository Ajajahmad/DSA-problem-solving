class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum =0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        
        int maxLength=-1,curSum=0;
        for(int l=0,r=0;r<n;r++)
        {
            curSum += nums[r];
            while(l<=r && curSum>sum-x) curSum-=nums[l++];
            if(curSum == sum-x) maxLength = max(maxLength , r-l+1);
        }
        return (maxLength==-1)? -1: n-maxLength;
    }
};