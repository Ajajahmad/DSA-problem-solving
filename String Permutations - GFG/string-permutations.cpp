// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
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
    vector<string> permutation(string nums)
    {
        vector<string> res;
            solve(nums , 0 ,res);
            sort(res.begin(),res.end());
            return res;
    }
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  // } Driver Code Ends