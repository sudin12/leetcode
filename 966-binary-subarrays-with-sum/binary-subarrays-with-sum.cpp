
class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) {
        std::unordered_map<int, int> prefixSumCount;
        int prefixSum = 0;
        int count = 0;
        
        // Traverse through the array and calculate prefix sums
        for (int num : nums) {
            prefixSum += num;
            if (prefixSum == goal)
                count++;
            // If there's a subarray with sum = prefixSum - goal, increase count
            if (prefixSumCount.find(prefixSum - goal) != prefixSumCount.end())
                count += prefixSumCount[prefixSum - goal];
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};