class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums , int i, int n , vector<int> &ds)
    {
        if(i==n)
        {
            res.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(nums , i+1, n, ds);
        ds.pop_back();
        solve(nums , i+1, n ,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ds;
        solve(nums , 0, nums.size() , ds);
        return res;
    }
};