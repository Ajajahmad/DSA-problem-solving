class Solution {
public:
    int countPalindromicSubsequences(string s) {
       int n = s.length();
        vector<int> pre(n), next(n);
        map<char, int> mp, m;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                pre[i] = -1;
            }
            else
            {
                pre[i] = mp[s[i]];
            }
            mp[s[i]] = i;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (m.find(s[i]) == m.end())
            {
                next[i] = -1;
            }
            else
            {
                next[i] = m[s[i]];
            }
            m[s[i]] = i;
        }

        int mod = (int)1e9 + 7;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    dp[i][j] = 2;
                }
                else if (s[i] == s[j])
                {
                    int n = next[i];
                    int p = pre[j];
                    if (n == j && p == i)
                    {
                        dp[i][j] = (2 * dp[i + 1][j - 1]) % mod + 2;
                    }
                    else if (n == p)
                    {
                        dp[i][j] = (2 * dp[i + 1][j - 1]) % mod + 1;
                    }
                    else
                    {
                        dp[i][j] = ((2 * dp[i + 1][j - 1]) % mod - dp[n + 1][p - 1] + mod) % mod;
                    }
                }
                else
                {
                    dp[i][j] = ((dp[i + 1][j] % mod + dp[i][j - 1] % mod)%mod - dp[i + 1][j - 1] + mod) % mod;
                }
            }
        }
        // if(dp[0][n-1]<0) return dp[0][n-1]+mod;
        return dp[0][n - 1];
    }
};