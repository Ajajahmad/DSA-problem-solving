class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0) return;
        if(m==0)
        {
            for(int i=0;i<n;i++) nums1[i]=nums2[i];
            return;
        }
        int i=0,j=0;
        while(i<m)
        {
            if(nums1[i]<= nums2[j])
            {
                i++;
            }
            else
            {
                int temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                i++;
                int x= j;
                while(j+1<n && nums2[j+1]<nums2[j])
                {
                    int c = nums2[j+1];
                    nums2[j+1] = nums2[j];
                    nums2[j] = c;
                    j++;
                }
                j = x;
            }
        }
        while(j<n)
        {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
};