class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // Create a hashmap to store the count of each element in nums1
        unordered_map<int, int> countMap;
        for (int num : nums1) {
            countMap[num]++;
        }

        // Create a vector to store the result
        vector<int> result;

        // Iterate through nums2 and find common elements
        for (int num : nums2) {
            if (countMap.find(num) != countMap.end() && countMap[num] > 0) {
                result.push_back(num);
                countMap[num]--;
            }
        }

        return result;
    }
};