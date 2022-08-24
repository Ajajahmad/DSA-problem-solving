class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length()<4) return res;
        string str="" , check="";
        int cnt = 0;
        
        solve(s, 0 , 0, res, cnt,  str,check);
        return res;
    }
    void solve(string &s , int i ,int num , vector<string> &res , int cnt,string str , string check)
    {
        if(cnt>3) return ;
        if(i==s.length())
        {
            if(cnt==3 && str[str.length()-1]!='.')
            {
                res.push_back(str);
                return;
            }
           
               return;
        }
        
        num = num*10+ (s[i]-'0');
        if(num>=0 && num<=255)
        {
            str += s[i];
            check += s[i];
            if(check[0] =='0' && check.size()!=1) return;
            
            str.push_back('.');
             // rakhte string me
             string a="";
            solve(s, i+1 , 0 ,res , cnt+1 , str , a);
            str.pop_back();
            // jab dot nhi le rhe
            solve(s , i+1, num , res, cnt , str,check);
        }
        else return;
       
        
    }
};