class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n  = numbers.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int low = i;
            int high = n-1;
            int  mid;
            int ans=-1;
            while(low<=high)
            {
                mid = low + (high-low)/2;
                if(mid != i && numbers[mid] == target-numbers[i])
                {
                    ans=mid;
                    break;
                }
                else if(numbers[mid] > target-numbers[i])
                {
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
            if(ans!=-1)
            {
                res.push_back(i+1);
                res.push_back(ans+1);
                break;
            }
        }
        return res;
    }
};