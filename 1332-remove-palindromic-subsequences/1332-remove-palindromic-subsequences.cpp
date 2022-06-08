class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        if(isPalindrome(s,0,n-1)) return 1;
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a') a=1;
            else b=1;
        }
        return a+b;
    }
    bool isPalindrome(string s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};