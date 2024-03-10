class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<bool> visited(1001, false); // Assuming integers are in the range [0, 1000]

        for (int num : nums1) {
            visited[num] = true;
        }

        for (int num : nums2) {
            if (visited[num]) {
                result.push_back(num);
                visited[num] = false; // Mark as visited to avoid duplicates
            }
        }

        return result;
    }
};