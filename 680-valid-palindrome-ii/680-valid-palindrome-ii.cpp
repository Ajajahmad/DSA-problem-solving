class Solution {
public:
    bool is(string s, int i , int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return is(s,i,j-1)||is(s,i+1,j);
            }
            i++;
            j--;
        }
        return true;
    }
};