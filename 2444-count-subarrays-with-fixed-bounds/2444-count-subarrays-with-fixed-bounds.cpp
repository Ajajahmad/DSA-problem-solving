class Solution {
public:
    long long countSubarrays(vector<int>& a, int minK, int maxK) {
         long res = 0;
        long n = a.size();
        long minI=-1 , mxI =-1 , i=0, j=0;
        for(int j =0;j<n;j++)
        {
             if(a[j]<minK || a[j]>maxK){
                 i = j+1;
                 minI = -1;
                 mxI = -1;
             }
            if(a[j]==minK ) minI =j;
            if(a[j]==maxK) mxI = j;
            res += max(0L,  min(minI , mxI )- i+1);
        }
        return res;
    }
};