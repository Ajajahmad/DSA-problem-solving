class Solution {
public:
    void solve(int ind , int target , vector<int>&a ,vector<vector<int>>& res,vector<int>&ds )
    {
        if(target==0){
            res.push_back(ds);
            return ;
        }
        for(int i=ind ; i<a.size();i++)
        {
            if(i>ind && a[i]==a[i-1]) continue;
            if(a[i]>target) break;
            ds.push_back(a[i]);
            solve(i+1 , target-a[i] , a,res,ds);
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> res;
        vector<int> ds;
        solve( 0 ,target , a, res , ds);
        return res;
    }
};