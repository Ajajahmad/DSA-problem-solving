class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i =0,j=0;
        int pre[n];
        pre[0]= 0;
        for( i=1;i<n;i++) pre[i] = pre[i-1]+nums[i-1];
        i=0;
        int sum=0;
        int mx=INT_MIN;
map<int,int> mp;
        while(j<n)
        {
            if(mp.find(nums[j])== mp.end() || mp[nums[j]]==0)
                mp[nums[j]]=j+1;
            else
            {
                int index = mp[nums[j]];
                sum = pre[j] - pre[index];
                
                for(int k=i;k<index;k++)
                {
                    mp[nums[k]]=0;
                }
                mp[nums[j]] = j+1;
                i=index;
                
            }
            sum += nums[j];
            mx=max(mx,sum);
            j++;
        }
        return mx;
    }
};