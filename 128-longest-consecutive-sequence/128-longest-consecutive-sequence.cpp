class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int res=1;
        int count =0, pre;
        for(auto it:mp)
        {
            if(count==0)
            {
                count++;
                pre = it.first;
            }
            else
            {
                if(it.first == pre+1)
                {
                    count++;
                    pre = it.first;
                }
                else
                {
                    count=1;
                    pre = it.first;
                }
                    
            }
            res = max(res , count);
        }
        return res;
    }
};