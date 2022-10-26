class Solution {
public:
    int fun(vector<int> &a, int n, int k)
    {
        unordered_map<int , int> mp, m ;
        int res = 0;
        int i = 0, j = 0;
        while(j<n)
        {
            m[a[j]] = j;
            mp[a[j]]++;

            if(mp.size() <=k )
            {
                res += (j-i+1);
            }
            else
            {
                int ind = m[a[i]];
                while(mp.size()>k) {
                    mp[a[i]]--;
                    if(mp[a[i]] == 0) mp.erase(a[i]);
                    i++;
                }
                res += (j-i+1);
            }
            j++;
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return fun(nums , n , k) - fun(nums , n , k-1);
    }
};