class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if the first i characters in s
        // match the first j characters in p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty pattern matches empty string
        dp[0][0] = true;
        
        // Handling '*' matches for empty string in s
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Fill dp array
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[m][n];
    }
};
