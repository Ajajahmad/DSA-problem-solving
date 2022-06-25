class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul =1;
        int n = nums.size();
        vector<int> res(n,1);
        for(int i=n-2;i>=0;i--)
        {
            res[i] = res[i+1]*nums[i+1];
            cout<<res[i]<<" ";
        }
        for(int i=1;i<n;i++)
        {
            res[i] = res[i]*(mul*nums[i-1]);
            mul =mul*nums[i-1];
        }
        return res;
    }
};