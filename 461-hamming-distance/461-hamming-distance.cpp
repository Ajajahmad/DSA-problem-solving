class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt=0;
        while(x!=0 || y!=0)
        {
            int a = 1&x ;
            int b = 1&y;
            if(a != b)
                cnt++;
            x = x>>1;
            y = y>>1;
        }
        return cnt;
    }
};