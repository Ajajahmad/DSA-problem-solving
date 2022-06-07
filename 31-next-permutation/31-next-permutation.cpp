class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n = nums.size();
        int i = n-2;
        while(i>=0)
        {
            if(nums[i]>=nums[i+1]) i--;
            else 
            {
                int j = -1;
                int v = INT_MAX;
                int k = i+1;
                while(k<n)
                {
                    if(nums[k]>nums[i] && nums[k] <=v)
                        v= nums[k],j=k;
                    k++;
                }
                int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                 j =n-1;
                i++;
                while(i<j)
                {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;
                    j--;
                }
                return;
            }
        }
        if(i<0)
        {
            int x=0,y=n-1;
            while(x<y)
            {
                int temp = nums[x];
                nums[x] = nums[y];
                nums[y] = temp;
                x++;
                y--;
            }
        }
    }
};