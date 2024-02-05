class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        int m = nums1.size();
        int n = nums2.size();
        int total_length = m + n;

        int left = 0, right = m;

        while (left <= right) {
            int partition_nums1 = (left + right) / 2;
            int partition_nums2 = (total_length + 1) / 2 - partition_nums1;

            int max_left_nums1 = (partition_nums1 == 0) ? INT_MIN : nums1[partition_nums1 - 1];
            int min_right_nums1 = (partition_nums1 == m) ? INT_MAX : nums1[partition_nums1];

            int max_left_nums2 = (partition_nums2 == 0) ? INT_MIN : nums2[partition_nums2 - 1];
            int min_right_nums2 = (partition_nums2 == n) ? INT_MAX : nums2[partition_nums2];

            if (max_left_nums1 <= min_right_nums2 && max_left_nums2 <= min_right_nums1) {
                if (total_length % 2 == 0) {
                    return (max(max_left_nums1, max_left_nums2) + min(min_right_nums1, min_right_nums2)) / 2.0;
                } else {
                    return max(max_left_nums1, max_left_nums2);
                }
            } else if (max_left_nums1 > min_right_nums2) {
                right = partition_nums1 - 1;
            } else {
                left = partition_nums1 + 1;
            }
        }

        throw invalid_argument("Input arrays are not sorted.");
    }
};
