class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        map<int,int> mp;
        int i=0, j=0;
        int res =-1;
        while(j<n)
        {
            mp[nums[j]]++;
            int mx= mp.begin()->first;
            int mn = mp.rbegin()->first;
            if(abs(mx-mn)<=limit) res = max(res,j-i+1);
            else 
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
                i++;
            }
            j++;
            
        }
        return res;
    }
};