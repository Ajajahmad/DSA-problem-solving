class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n<4) return {};
        sort(nums.begin() , nums.end());
        vector<vector<int>> res;
        map<vector<int> , int > mp;
        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-1;j++)
            {
                if(j>i+1&& nums[j]==nums[j-1]) continue;
                int l = j+1,r= n-1;
                
                while(l<r)
                {
                    long long int sum = nums[i] ;
                   sum += nums[j] ;
                    sum += nums[l] ;
                    sum += nums[r];
                    if(sum == target){
                        mp[{nums[i] , nums[j] , nums[l] , nums[r]}]++;
                        l++;
                    }
                    else if(sum > (long long )target){
                        r--;
                    }
                    else
                    {
                        l++;
                    }
                }
                    
            }
        }
        for(auto it:mp){
            res.push_back(it.first);
        }
        return res;
    }
};