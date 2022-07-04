class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        
        int i=0;
        while(i<n)
        {
            int count=0, j =i;
            while(j+1<n && nums[j+1]<nums[j])
            {
                count++;
                j++;
            }
            count++;
            if(i!=0 && nums[i]>nums[i-1] && res[i-1]>= count)
            {
                res[i] =res[i-1] +1;
                count--;
                i++;
            }
            while(count>0)
            {
                res[i++] = count;
                count--;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum += res[i];
        return sum;
    }
};