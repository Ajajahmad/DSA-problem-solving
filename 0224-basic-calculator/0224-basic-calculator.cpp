class Solution {
public:
    int calculate(string s) {
        int result=0;
        int sn=1; 
        int j=0;
        int len=s.length();
        stack<int> stk;
        
        while(j<len){ 
            if(s[j]=='+')
            {
                sn=1;
            }
            else if(s[j]=='-')
            {
                sn=-1;
            }
            else if(isdigit(s[j]))
            {
                //get the number 
                int num=s[j]-'0';
                while(j+1<len && isdigit(s[j+1])){
                    num=num*10+(s[j+1]-'0');
                    j++;
                }
                result+=num*sn;
            }
            else if(s[j]=='(')
            {
                stk.push(result);
                stk.push(sn);
                result=0;
                sn=1;
            }
            else if(s[j]==')')
            {
                int xsign=stk.top();
                stk.pop();
                int xresult=stk.top();
                stk.pop();
                result=result*xsign + xresult;
            }
            j++;
        }
        return result;
    }
};