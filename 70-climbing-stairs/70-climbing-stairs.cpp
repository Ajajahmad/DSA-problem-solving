class Solution {
public:
    
    int climbStairs(int n) {
   
        int a = 1, b=2, c;
       if(n==1) return 1;
        
        for(int i=3;i<=n;i++) 
        {
            c= a+b;
           a= b;
            b=c;
        }
        return b;
        
    }
    
};