class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int k = 1; // Number of unique elements
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        
        return k;
    }
};