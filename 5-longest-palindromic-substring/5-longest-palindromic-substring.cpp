class Solution {
public:
    string longestPalindrome(string S) {
        int n = S.size();
        int maxlength=1,start=0;
        int low,high;
        for(int i=0;i<n;i++)
        {
            low = i-1;
            high = i+1;
            while(high<n && S[high]==S[i])
                high++;
            while(low>=0 && S[low]==S[i])
                low--;
            while(low>=0 && high<n && S[low]==S[high])
            {
                low--;
                high++;
            }
            if(maxlength<high-low-1)
            {
                maxlength = high-low-1;
                start = low+1;
            }
        }
        string res= S.substr(start,maxlength);
        return res;
    }
};