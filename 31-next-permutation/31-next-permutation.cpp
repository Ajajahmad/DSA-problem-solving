class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return;
        int i,k;
        for( i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1])
            {
                break;
            }
        }
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                k=j;
                break;
            }
        }
        swap(nums[i],nums[k]);
        sort(nums.begin()+i+1,nums.end());
        }
    }
};