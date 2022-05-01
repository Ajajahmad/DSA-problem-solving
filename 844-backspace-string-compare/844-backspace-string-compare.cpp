class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0;
        int n = s.length(), m=t.length();
        while(i<n)
        {
            if(s[i]=='#' && i!=0)
            {
                string str="";
                str = s.substr(0,i-1) + s.substr(i+1,n-i-1);
                i-=1;
                s=str;
                n-=2;
            }
            else 
                i++;
        }
        i=0;
        while(i<m)
        {
            if(t[i]=='#' && i!=0)
            {
                string str="";
                str = t.substr(0,i-1) + t.substr(i+1,m-i-1);
                i=0;
                m-=2;
                t= str;
            }
            else 
                i++;
        }
        i=0;
        int j=0;
        while(s[i]=='#') i++;
        while(t[j]=='#') j++;
        while(i<n && j<m)
        {
            if(s[i]!=t[j]) return false;
            i++;
            j++;
        }
        if(i!=n || j!=m) return false;
        return true;
    }
};