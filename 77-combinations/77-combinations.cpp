class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>>res;
        vector<int> ans;
                if(k>n || k<=0) return res;
       
        solve(1,n,k,res,ans);
        return res;
    }
    void solve(int i , int n , int k ,vector<vector<int>>&res ,vector<int> &ans)
    {
        if(k==0)
        {
            res.push_back(ans);
            return;
        }
        
        for(int x=i;x<=n-k+1;x++)
        {
            ans.push_back(x);
            solve(x+1 , n , k-1, res,ans);
            ans.pop_back();
            
        }
    }
};