class Solution {
public:
    int s[200][200][300];
    bool isInterleave(string s1, string s2, string s3) {
        int n1= s1.length(), n2=s2.length(), n3= s3.length();
        if(n3 !=n1+n2) return false;
        memset(s , -1, sizeof(s));
        
        return solve(s1,s2,s3,n1,n2,n3);
    }
    
    bool solve(string s1, string s2, string s3, int i, int j, int k)
    {
        if(i<=0 &&j<=0 && k<=0) return true;
        
       if(s[i][j][k]!=-1) return s[i][j][k];
        if(i>0 && j>0 && k>0 && s1[i-1]==s3[k-1] && s2[j-1]==s3[k-1])
        {
            return s[i][j][k] = (solve(s1,s2,s3, i-1,j,k-1) || solve(s1,s2,s3,i,j-1,k-1) );
        }
        else if(i>0 && j>0 && k>0 && s1[i-1]!=s3[k-1] && s2[j-1]==s3[k-1])
        {
            return s[i][j][k]= solve(s1,s2,s3,i,j-1,k-1);
        }
        else if(i>0 && j>0 && k>0 && s1[i-1]==s3[k-1] && s2[j-1]!=s3[k-1])
        {
            return s[i][j][k] =solve(s1,s2,s3,i-1,j,k-1);
        }
        else if(i<=0 && j>0 && k>0 && s2[j-1]==s3[k-1])
        {
            return s[i][j][k]= solve(s1,s2,s3,i,j-1,k-1);
        }
        else if(i>0 && j<=0 && k>0 && s1[i-1]==s3[k-1])
        {
            return s[i][j][k]= solve(s1,s2,s3,i-1,j,k-1);
        }
        else
            return s[i][j][k] = false;
        
    }
};