class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count_ones = count(nums.begin(), nums.end(), 1);
        if (count_ones == 0) return 0;

        vector<int> extended_nums(nums.begin(), nums.end());
        extended_nums.insert(extended_nums.end(), nums.begin(), nums.end());

        int current_zeroes = count(extended_nums.begin(), extended_nums.begin() + count_ones, 0);
        int min_zeroes = current_zeroes;

        for (int i = count_ones; i < extended_nums.size(); ++i) {
            if (extended_nums[i] == 0) current_zeroes++;
            if (extended_nums[i - count_ones] == 0) current_zeroes--;

            min_zeroes = min(min_zeroes, current_zeroes);
        }

        return min_zeroes;
    }
};
