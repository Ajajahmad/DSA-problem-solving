// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	     void solve(string nums , int index , vector<string>&res)
        {
            if(index== nums.length())
            {
                res.push_back(nums);
                return;
            }
            for(int i=index ; i<nums.length();i++)
            {
                swap(nums[i],nums[index]);
                solve(nums , index+1 , res);
                swap(nums[i] , nums[index]);
            }
        }
		vector<string>find_permutation(string nums)
		{
		    vector<string> res;
            solve(nums , 0 ,res);
            sort(res.begin(),res.end());
            return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends