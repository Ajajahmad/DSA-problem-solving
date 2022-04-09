class Solution {
public:
    void solve(vector<int> &nums , int index , vector<vector<int>>&res)
    {
        if(index== nums.size())
        {
            res.push_back(nums);
            return;
        }
        for(int i=index ; i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            solve(nums , index+1 , res);
            swap(nums[i] , nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums , 0 ,res);
        return res;
    }
};