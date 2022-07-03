class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos=0,neg =0;
        while(pos<n && nums[pos]<=0)
            pos++;
        while(neg<n && nums[neg]>=0)
            neg++;
        if(pos==n || neg==n || n<2) return nums;
        
       vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            if(i%2==0 || neg==n)
            {
                res[i] = nums[pos++];
            }
            else
            {
                res[i] = nums[neg++];
            }
            while(pos<n && nums[pos]<=0)
                pos++;
            while(neg<n && nums[neg]>=0)
                neg++;
        }
        return res;
        
    }
};