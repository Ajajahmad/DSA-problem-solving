class Solution {
public:
    int countOdds(int low, int high) {
        int range = high - low +1;
        if(range%2==0)
        {
            return range/2;
        }
        if(low%2!=0)
        {
            return range/2+1;
        }
        return range/2;
    }
};