class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n, 0) ;
        vector<int> res;
        
        pre[0] = nums[0];
        for(int i = 1;i<n ;i++) pre[i] = pre[i-1]+nums[i];
        for(int i=0;i<n;i++)
        {
            if(i-k<0 || i+k>=n){
                res.push_back(-1);
                continue;
            }
            res.push_back((pre[i+k] - pre[i-k] + nums[i-k])/(2*k+1));
        }
        return res;
    }
};