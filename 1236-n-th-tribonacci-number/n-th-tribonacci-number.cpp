class Solution {
public:
 int memoziation(int n, vector<int>& dp) {
        if(n <= 1)  return n;
        if(n == 2)  return 1;

        // if the value is previously computed, the recursive call will not be called
        if(dp[n] != -1) return dp[n];

        dp[n] = memoziation(n-1, dp)+memoziation(n-2, dp)+memoziation(n-3, dp);

        return dp[n];
    }
    int tribonacci(int n) {
        vector<int> dp(n+1, -1);
        return memoziation(n, dp);
    }
};