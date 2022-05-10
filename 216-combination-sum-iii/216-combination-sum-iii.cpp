class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
       
        vector<int> ans;
        
        solve(k,n, 1 ,res,ans);
        return res;
    }
    void solve(int k , int n, int i,vector<vector<int>>&res, vector<int>&ans )
    {
        if(k==0)
        {
                int sum=0;
                for(int x=0;x<ans.size();x++)
                {
                    sum += ans[x];
                }
                if(sum == n)
                    res.push_back(ans);
            return;
        }
        if(i>9)
        {
            return;
        }
       
        ans.push_back(i);
        solve(k-1 , n,i+1,res,ans);
        ans.pop_back();
        solve(k , n ,i+1,res,ans);
    }
};