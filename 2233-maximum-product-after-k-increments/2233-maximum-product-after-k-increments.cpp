class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int n = nums.size();
        long long mul = 1;
       int mod = 1e9+7;
        
        priority_queue<int, vector<int>, greater<int>> pq;
         for(auto a:nums) 
         {
             
             pq.push(a);
        }
        // cout<<mul<<endl;
        
        while(k--)
        {
            int tp = pq.top();
            pq.pop();
         
            tp++;
            pq.push(tp);
        }
        while(pq.size())
        {
            int tp = pq.top();
            pq.pop();
            mul = (mul%mod * tp%mod)%mod;
        }
        
        
        return mul;
    }
};