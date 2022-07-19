class Solution {
public:
    int tribonacci(int n) {
        int a =0;
        if(n==0) return 0;
        int b =1,c=1;
        if(n==1) return b;
        if(n==2) return c;
        for(int i=3;i<=n;i++)
        {
            int d= a+b+c;
            a=b;
            b=c;
            c=d;
        }
        return c;
    }
};