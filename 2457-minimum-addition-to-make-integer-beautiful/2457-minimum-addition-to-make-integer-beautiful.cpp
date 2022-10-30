class Solution {
public:
    int sum(long long num)
    {
        int res = 0;
        while(num)
        {
            res += num%10;
            num  = num/10;
        }
        return res;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long num = n;
        long long count = 1;
        while(sum(num)>target)
        {
            num = num/10+1;
            count = count*10;
        }
        return num*count-n;
    }
};