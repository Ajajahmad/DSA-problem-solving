class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int  i=0,j=0,k=0;
        
        while(j<n)
        {
            if(s[j]!=' ' || j==0)
            {
                j++;
                
            }
            else if(s[j]==' ')
            {
                k=j-1;
                while(i<k)
                {
                    char temp = s[i];
                    s[i]=s[k];
                    s[k]=temp;
                    k--;
                    i++;
                }
                k=j+1;
                i=j+1;
                
                j++;
                
            }
            
        }
        reverse(s.begin()+i,s.end());
        return s;
    }
};