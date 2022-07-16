class Solution {
public:
    bool find_i_th_bit_is_1_or_Not(int i,uint32_t n) // finding ith bit is 1 or not
    {
        if(((1<<(i-1)) & n)!=0)
            return true;
        else
            return false;
    }
    uint32_t reverseBits(uint32_t n) {
      uint32_t ans=0;
       for(int i=1; i<=32; i++)
       {
           if(find_i_th_bit_is_1_or_Not(i,n))  // if ith bit is one then do bit wise OR 
               ans = ans | (1<<(32-i));
       }
        return ans;
    }

};