class Solution {
public:
    void recur(vector<int> &nums, vector<int>&ds , vector<vector<int>> &res , int a[])
    {
        if(ds.size()==nums.size()) 
        {
            res.push_back(ds);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!a[i])
            {
                ds.push_back(nums[i]);
                a[i]=1;
                recur(nums , ds, res, a);
                a[i]=0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>ds;
        int a[nums.size()];
        for(int i=0;i<nums.size();i++) a[i]=0;
        recur(nums,ds,res,a);
        return res;
    }
};