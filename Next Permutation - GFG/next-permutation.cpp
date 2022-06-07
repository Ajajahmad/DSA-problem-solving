// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
        vector<int> nextPermutation(int n, vector<int> nums){
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
                    return nums;
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
            return nums;
        }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends