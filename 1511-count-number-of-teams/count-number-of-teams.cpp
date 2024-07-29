class Solution {
public:
    int solve(int i, int prev, int n, int cnt, vector<int> &arr,  vector<vector<vector<int>>> &dp)
    {
        if(cnt == 3) return 1;
        if(i == n) return 0;
        if (dp[i][prev+1][cnt] != -1) return dp[i][prev+1][cnt];
        int pick = 0, skip = 0;
        if(prev == -1 || arr[i] > arr[prev])
        {
            pick = solve(i+1, i, n, cnt+1, arr, dp);
        }
        skip = solve(i+1, prev, n, cnt, arr, dp);
        return dp[i][prev+1][cnt] = pick + skip;
    }

    int numTeams(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+2, vector<int>(4, -1)));
        int a = solve(0,-1,n,0,arr, dp);
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < n+1; ++i) {
            for (int j = 0; j < n+2; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int b = solve(0,-1,n,0,arr, dp);
        return a+b;
    }
};