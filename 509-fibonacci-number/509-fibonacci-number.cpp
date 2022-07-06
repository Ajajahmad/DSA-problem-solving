class Solution {
public:
    int fib(int n) {
        int a=1,b=1;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        for(int i=3;i<=n;i++)
        {
            int c= a+b;
            a=b;
            b=c;
        }
        return b;
    }
};