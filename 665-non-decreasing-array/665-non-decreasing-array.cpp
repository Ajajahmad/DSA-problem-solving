class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                if(i==0)
                {
                    nums[i] = nums[i+1];
                    break;
                }
            
                if(i==n-2)
                {
                        nums[i+1] = nums[i];
                        break;
                }
                if(nums[i+1]<=nums[i+2] && nums[i-1]<=nums[i+1])
                {
                            nums[i] = nums[i-1];
                            break;

                }
                    nums[i+1] = nums[i];
                    break;
                
            }
            
           
        }
         for(int i=0;i<n-1;i++){
                if(nums[i]>nums[i+1]) return false;
            }
            return true;
    }
};