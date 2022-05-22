class Solution {
public:
    int minimumLines(vector<vector<int>>& st) {
        int n = st.size();
        if(n==1) return 0;
        if(n==2) return 1;
        int res=0;
        long double pre=-1;
        sort(st.begin(),st.end());
        for(int i=1;i<n;i++)
        {
            long double num = st[i][1] - st[i-1][1];
          long  double den = st[i][0] - st[i-1][0];
            
           long double curr = num/den;
            if(res==0)
            {
                res++;
                pre = curr;
            }
            else
            {
               if(curr!=pre)
               {
                   res++;
                   pre = curr;
               }
            }
        }
        return res;
    }
};