class Solution {
public:
    bool isHappy(int n) {
        map<int,int> mp;
        while(n!=1)
        {
            if(mp.find(n)!=mp.end()) return false;
            mp[n]++;
            int num = n;
            int sum =0 ;
            while(num!=0)
            {
                int rem = num%10;
                sum += rem*rem;
                num = num/10;
            }
            n = sum;
        }
        return true;
    }
};