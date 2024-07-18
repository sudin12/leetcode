/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> solve(TreeNode* root, int& distance, int& ans) {
        if (!root) {
            return vector<int>(distance + 1, 0);
        }
        if (root->left == nullptr && root->right == nullptr) {
            vector<int> v(distance + 1, 1);
            v[0] = 0;
            return v;
        }

        vector<int> leftt = solve(root->left, distance, ans);
        vector<int> rightt = solve(root->right, distance, ans);

        vector<int> v(distance + 1, 0);
        for (int i = 1; i < distance; i++) {
            int leftCount = leftt[i] - leftt[i - 1];
            int rightCount = rightt[i] - rightt[i - 1];
            ans += (leftCount)*rightt[distance - i];
            v[i + 1] = v[i] + leftCount + rightCount;
        }
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        solve(root, distance, ans);
        return ans;
    }
};