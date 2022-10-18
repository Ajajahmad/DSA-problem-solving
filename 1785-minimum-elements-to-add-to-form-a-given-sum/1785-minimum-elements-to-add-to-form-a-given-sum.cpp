class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
         int n = nums.size();
        long long sum  =0 ;
        for(int i=0;i<n ;i++) sum+= nums[i];
        
        if(sum==goal) return 0;
        long long dif = abs(goal-sum);
        long long count = dif/limit;
        if(dif %limit==0) return count;
        return count+1;
    }
};