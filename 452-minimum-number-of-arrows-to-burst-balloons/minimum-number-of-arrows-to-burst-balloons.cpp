class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort balloons based on the end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int end = points[0][1];
        
        // Iterate through balloons
        for (int i = 1; i < points.size(); ++i) {
            // If the next balloon starts after the current end, a new arrow is needed
            if (points[i][0] > end) {
                ++arrows;
                end = points[i][1];
            }
        }
        
        return arrows;
    }
};
