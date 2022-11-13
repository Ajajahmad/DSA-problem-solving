class Solution {
public:
    string reverseWords(string s) {
       string res = "";
        int  n = s.length() ,j=n-1 , i=n-1;
        while(i>=0){
            while(i>=0&& s[i]==' ')i--;
            j=i;
            while(i>=0 && s[i]!=' ') i--;
            res+= s.substr(i+1, j-i);
            res+= ' ';
        }
        i = res.length()-1;
        while(res[i]==' ')
        {
            res.pop_back();
             i = res.length()-1;
        }
        return res;
        
    }
};