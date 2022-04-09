// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	map<string ,int> mp;
	  void solve(string nums , int index , vector<string>&res)
        {
            if(index== nums.length())
            {
                if(mp.find(nums)==mp.end())
                {
                    res.push_back(nums);
                    mp[nums]++;
                    
                }
                return;
            }
            for(int i=index ; i<nums.length();i++)
            {
                swap(nums[i],nums[index]);
                solve(nums , index+1 , res);
                swap(nums[i] , nums[index]);
            }
        }
	vector<int> permutaion(int N) {
	    string nums = to_string(N);
	    vector<string> res;
            solve(nums , 0 ,res);
            sort(res.begin(),res.end());
        vector<int> ans;
        ans.push_back(res.size());
        int sum=0;
        for(int i=0;i<res.size();i++)
        {
            int n = stoi(res[i]);
            sum += n;
        }
        ans.push_back(sum);
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.permutaion(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}  // } Driver Code Ends