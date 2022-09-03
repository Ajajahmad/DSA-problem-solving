class Solution {
public:
    vector<int> res;
    map<int , int> mp;
    vector<int> numsSameConsecDiff(int n, int k) {
        
        
        for(int i=1;i<=9;i++)
        {
            solve(1 , n , k, i);
        }
        return res;
    }
    void solve(int sz , int n , int k, int num)
    {
        if(sz==n)
        {
            if(mp.find(num)==mp.end())
            {
                res.push_back(num);
                mp[num]++;
            }
            return ;
        }
        int rem = num%10;
        if(rem-k>=0)
            solve(sz+1, n , k, num*10+(rem-k));
        if(rem+k<10)
            solve(sz+1 , n , k, num*10+(rem+k));
    }
};