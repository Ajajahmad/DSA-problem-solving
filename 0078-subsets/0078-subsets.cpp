class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        solve(nums , 0 , temp);
        return res;
    }
    void solve(vector<int>&nums, int i , vector<int> & temp)
    {
        int n = nums.size();
        if(i==n)
        {
            res.push_back(temp);
            return;
        }
        
        solve(nums , i+1, temp);
        temp.push_back(nums[i]);
        solve(nums, i+1, temp);
        temp.pop_back();
    }
};