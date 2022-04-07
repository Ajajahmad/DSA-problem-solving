class Solution {
public:
    vector<vector<int>> res;
    map<vector<int> , int >mp;
    void solve(vector<int>&a , int target , int i , int sum , vector<int> &ds , int n)
    {
        if(i==n)
        {
            if(sum==target)
            {
                if(mp.find(ds)==mp.end())
                {
                    res.push_back(ds);
                    mp[ds]++;
                }
                
            }
            return ;
        }
        if(target==sum)
        {
             if(mp.find(ds)==mp.end())
                {
                    res.push_back(ds);
                    mp[ds]++;
                }
            return ;
        }
        else if(target<sum)
        {
            return ;
        }
        solve(a , target ,i+1 , sum ,ds , n);
        ds.push_back(a[i]);
        solve(a , target , i+1 , sum+a[i], ds ,n);
        ds.pop_back();
        ds.push_back(a[i]);
        solve(a, target , i , sum+a[i], ds ,n);
        ds.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        solve(candidates , target , 0 , 0 ,ds, candidates.size());
        return res;
    }
};