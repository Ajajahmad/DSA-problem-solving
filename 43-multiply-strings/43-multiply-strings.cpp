class Solution {
public:
    void solve(string &res , string &str, int cnt)
    {
        while(cnt--){
                    str += '0';
        }

        reverse(res.begin() , res.end());
         reverse(str.begin() , str.end());
        int n= res.length();
        int m = str.length(), rem=0;
        string final="";
        int c1,c2,f;
        char ch;
        for(int i=0;i<m;i++)
        {
            if(i>=n){
                c2 = str[i]-'0';
                f = c2+rem;
                rem = f/10;
                f =f%10;
                ch = f+'0';
                final += ch;
                continue;
            }
            else if(i>=m){
                c1 = res[i]-'0';
                f = c1+rem;
                rem = f/10;
                f =f%10;
                ch = f+'0';
                final += ch;
                continue;
            }
            else
            {
                c1 = res[i]-'0';
                c2 = str[i]-'0';
                f = c1+c2+rem;
                rem = f/10;
                f =f%10;
               ch = f+'0';
                final += ch;
            }
            
        }
        if(rem>0)
        {
            ch = rem+'0';
            final += ch;
        }
        reverse(final.begin() , final.end());
        res = final;
    }
    
    
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int m = num2.length();
        int n = num1.length();
        int count=0;
        string res="";
        char ch,c,chh;
        int mul,d,r;
        int rem,cnt=1;
        for(int i=m-1;i>=0;i--)
        {
            ch = num2[i];
            mul = ch-'0';
            
            rem=0;
            string str="";
            
            for(int j=n-1;j>=0;j--)
            {
                c= num1[j];
                d = c-'0';
                r = mul*d +rem;
                rem = r/10;
                r = r%10;
                char chh = r+'0';
                str+=chh;
            }
            if(rem>0)
            {
                char c1 = rem+'0';
                str+=c1;
                
            }
            
            reverse(str.begin(),str.end());
            
            
            
            if(count==0)
            {
                res=str;
                count++;
            }
            else
            {
                solve(res ,str,cnt);
                cnt++;
            }
            
        }
        return res;
    }
};