class NumArray {
public:
    vector<int> temp,a;
    NumArray(vector<int>& nums) {
        a = nums;
        int n = nums.size();
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            temp.push_back( temp[i-1] + nums[i] ); 
        }
    }
    
    int sumRange(int left, int right) {
        return temp[right] - temp[left] + a[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */