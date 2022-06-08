class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int i=0,one=0;
        int mod = 1e9+7;
        long long int res=0;
        while(i<n)
        {
            if(s[i]=='0'){
                long long int va = one ;
                va = (va *(one+1))/2;
                res += va%mod;
                res%=mod;
                one = 0;
            }
            else if(s[i]=='1') one++;
            i++;
        }
        if(s[n-1]=='1'){
            long long int va = one ;
                va = (va *(one+1))/2;
                res += va%mod;
                res%=mod;
        }
        return res;
    }
};