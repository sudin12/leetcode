class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;

        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                duplicates.push_back(index + 1);
            } else {
                nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = abs(nums[i]);
        }

        return duplicates;
    }
};