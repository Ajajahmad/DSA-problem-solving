class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int l=0,r=0;
        int n = nums.length;
        int cursum =0 , res=0;
        while(l<n && r<n)
        {
            cursum+= nums[r];
            if(cursum<goal)
                r++;
            else if(cursum>goal)
            {
                l++;
                r = l;
                cursum=0;
            }
            else 
            {
                res++;
                r++;
                if(r==n){
                    l++;
                    r = l;
                    cursum=0;
                }
            }
        }
        return res;
    }
}