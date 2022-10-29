class Solution {
public:
    int numberOfSubstrings(string s) {
        int n =s.length();
        int a = 0 , b= 0 ,c=0;
        int res =0 , i =0 , j=0;
        while(j<n){
            if(s[j]=='a') a++;
            else if(s[j]=='b') b++;
            else if(s[j]=='c') c++;
            while(a && b && c) 
            {
                if(s[i]=='a') a--;
                else if(s[i]=='b') b--;
                else if(s[i]=='c') c--;
                i++;
            }
            res += i;
            j++;
        }
        return res;
    }
};