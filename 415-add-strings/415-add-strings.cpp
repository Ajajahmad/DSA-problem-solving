class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        string res = "";
        int i = n-1, j = m-1;
        int rem = 0;
        while(i>=0 || j>=0)
        {
            int v1 = (i<0)? 0 : num1[i]-'0';
            int v2 = (j<0)? 0 : num2[j]-'0';
            int sum = v1+v2+rem;
            rem = sum/10;
            sum= sum%10;
            char ch = '0'+sum;
            res += ch;
             i--;
            j--;
        }
        if(rem>0)
        {
            char ch = '0'+rem;
            res += ch;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};