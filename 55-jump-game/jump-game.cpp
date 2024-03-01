class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) return false; // If current index is unreachable
            maxReach = max(maxReach, i + nums[i]); // Update the maximum reachable index
            if (maxReach >= nums.size() - 1) return true; // If the last index is reachable
        }
        return false;
    }
};