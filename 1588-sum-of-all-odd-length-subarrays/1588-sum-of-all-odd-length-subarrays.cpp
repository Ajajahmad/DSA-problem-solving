class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), k=1;
        int i = 0, j =0;
        int res=0,sum=0;
        while(k<=n)
        {
            sum=0;
            while(j<n)
            {
                sum+=arr[j];
                if(j-i+1<k) j++;
                else
                {
                    res+=sum;
                    sum-=arr[i++];
                    j++;
                }
            }
            k=k+2;
            j=0;
            i=0;
        }
        return res;
    }
};