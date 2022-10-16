class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        map<vector<int> , int> mp;
        int res=0;
        
        for(int i=0 ;i<n;i++)
        {
            int x = i, y= i;
            int dv = 0;
            vector<int> temp;
            while(y<n)
            {
                temp.push_back(nums[y]);
                if(nums[y]%p==0) dv++;
                if(dv<=k && mp.find(temp)==mp.end())
                {
                    res++;
                }
                else if(dv>k)
                {
                    break;
                }
                mp[temp]++;
                y++;
            }
        }
        return res;
    }
};