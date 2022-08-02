class Solution {
public:
    int check(vector<vector<int>> &a, int mid)
    {
        int n=a.size();
        int count =0,j=n-1;
        for(int i=0;i<n;i++)
        {
            while(j>=0 && a[i][j]>mid) j--;
            count += j+1;
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),ans=-1;
        int start = matrix[0][0];
        int end = matrix[n-1][n-1]+1;
        while(start<end)
        {
            int mid = start + (end-start)/2;
            if(check(matrix,mid)>=k)
            {

                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        return  start;
    }
};