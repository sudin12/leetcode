class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Already at the destination or no elements to jump

        int jumps = 0;
        int currentMaxReachable = 0; // Current maximum reachable index
        int nextMaxReachable = 0;    // Maximum reachable index considering the next jump

        for (int i = 0; i < n - 1; i++) {
            nextMaxReachable = max(nextMaxReachable, i + nums[i]); // Update the maximum reachable index
            if (i == currentMaxReachable) { // Need to make a jump
                jumps++;
                currentMaxReachable = nextMaxReachable;
                if (currentMaxReachable >= n - 1) break; // Reached or exceeded the destination
            }
        }

        return jumps;
    }
};