class Solution {
public:
    vector<vector<int>> res;
    map<vector<int> , int> mp;
    void solve(vector<int> &nums , int i, int n , vector<int> &ds)
    {
        if(i==n)
        {
            if(mp.find(ds)==mp.end())
            {
                mp[ds]++;
                res.push_back(ds);
            }

            return;
        }
        
        solve(nums , i+1, n ,ds);
        ds.push_back(nums[i]);
        solve(nums , i+1, n, ds);
        ds.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        solve(nums , 0, nums.size() , ds);
        return res;
    }
};