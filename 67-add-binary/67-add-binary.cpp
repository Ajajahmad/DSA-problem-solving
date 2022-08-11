class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length(), i=n-1,j=m-1;
        int carry  =0 , s1=0,s2=0;
        string str = "";
        while(i>=0 || j>=0)
        {
            if(i<0)
                s1=0;
            else
                s1 = a[i]-'0';
            if(j<0)
                s2 = 0;
            else 
                s2 = b[j]-'0';
            int sum = s1+s2+carry;
            if(sum==0)
            {
                carry = 0;
                str+='0';
            }
            else if(sum==1)
            {
                carry = 0;
                str+='1';
            }
            else if(sum==2)
            {
                carry =1;
                str+='0';
            }
            else if(sum==3)
            {
                carry = 1;
                str+='1';
            }
            i--;
            j--;
        }
        if(carry ==1)
            str+='1';
        else if(carry ==2)
        {
            str+='0';
            str+='1';
        }
        reverse(str.begin(), str.end());
        return str;
    }
};