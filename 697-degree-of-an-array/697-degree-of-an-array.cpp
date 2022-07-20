class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] ++;
            
        }
        int digit = 0;
        int val =0;
        for(auto it:mp)
        {
            if(val < it.second)
            {
                val = it.second;
                digit = it.first;
            }
        }
        vector<int>temp;
        for(auto it:mp)
        {
            if(it.second==val)
                temp.push_back(it.first);
        }
        int res= INT_MAX;
        for(int j=0;j<temp.size();j++)
        {
            digit = temp[j];
            int  b=-1, e=-1,count=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==digit)
                {
                    if(count==0)
                    {
                        b= i;
                        e = i;
                        count++;
                    }
                    else
                        e=i;
                }
            }
            res = min(res , e-b+1);
        }
        
        
        return res;
    }
};