class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum =0 ;
        int n = nums.size();
        for(int i=0;i<n;i++) 
            if(nums[i]%2==0)
                sum += nums[i];
        vector<int> res;
        for(int i=0;i<queries.size() ; i++){
            int index = queries[i][1];
            int val = queries[i][0];
            if(abs(nums[index]) %2==0)
            {
                if(abs(val)%2==0)
                {
                    sum += val;
                    nums[index] = nums[index]+val;
                }
                else 
                {
                    sum -= nums[index];
                    nums[index] = nums[index]+val;
                }
            }
            else
            {
                if(abs(val)%2==0)
                {
                    nums[index] = nums[index]+val;
                }
                else 
                {
                    sum +=  nums[index]+val;
                    nums[index] = nums[index]+val;
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};