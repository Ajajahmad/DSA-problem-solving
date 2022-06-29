// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        solve(nums, res, 0, n-1);
        return res;
        
    }
    void solve(vector<int>& nums,vector<int>& res , int l , int r)
    {
        if(l>r) return;
        int m = l+(r-l)/2;
        res.push_back(nums[m]);
        solve(nums,res, l, m-1);
         solve(nums,res, m+1, r);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends