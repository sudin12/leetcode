class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, result, current, 0);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int start) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(current);
            return;
        } else {
            for (int i = start; i < candidates.size(); ++i) {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], result, current, i);
                current.pop_back();
            }
        }
    }
};
