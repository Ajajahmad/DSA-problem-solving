class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.length(),n=str2.length();
        int dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        string str="";
        int i=m,j=n;
        while(i>0 && j>0)
        {
            if(str1[i-1] == str2[j-1])
            {
                str.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i][j-1]>dp[i-1][j])
                    j--;
                else
                    i--;
            }
        }
        reverse(str.begin(),str.end());
        i=0;
        j=0;
        int k=0;
        string res="";
        while(k<str.length())
        {
            if(str[k]==str1[i] && str[k]==str2[j])
            {
                res.push_back(str[k]);
                i++;
                j++;
                k++;
            }
            else
            {
                if(str1[i]!=str[k])
                {
                    res.push_back(str1[i]);
                    i++;
                }
                else if(str2[j]!=str[k])
                {
                    res.push_back(str2[j]);
                    j++;
                }
            }
        }
        while(i<str1.length())
        {
            res.push_back(str1[i]);
            i++;
        }
        while(j<str2.length())
        {
            res.push_back(str2[j]);
                j++;
        }
        return res;
    }
};