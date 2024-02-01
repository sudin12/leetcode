class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        // dp[i][j] will be true if the first i characters in s match the first j characters in p
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Empty string and empty pattern always match
        dp[0][0] = true;

        // Deals with patterns like a* or a*b* or a*b*c*
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Matches zero preceding elements
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // Matches one or more preceding elements
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};
