class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
         
        stack<int> st;
        vector<int> res;
        int n = nums.size();
        for(int i=n-1;i>=0; i--)
        {
            if(st.size() == 0 )
            {
                int j =0;
                while(j<i && nums[j]<=nums[i] ) j++;
                if(i==j ) res.push_back(-1);
                else res.push_back(nums[j]);
                st.push(nums[i]);
            }
            else{
                while(st.size()!=0 &&  st.top() <= nums[i]) st.pop();
                if(st.size()!=0){
                    res.push_back(st.top());
                    st.push(nums[i]);
                }
                else
                {
                    int j =0;
                    while(j<i && nums[j]<=nums[i] ) j++;
                    if(i==j) res.push_back(-1);
                    else res.push_back(nums[j]);
                    st.push(nums[i]);
                }
            }
        }
        reverse(res.begin() , res.end());
        return res;
    }
};