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
    vector<string> res;
    void f(TreeNode* root, string answer) {
        if (root == NULL)
            return;
        if (root->left == NULL & root->right == NULL) {
            answer += 'a' + root->val;
            reverse(answer.begin(), answer.end());
            res.push_back(answer);
            answer.clear();
            return;
        }
        answer += 'a' + root->val;
        f(root->left, answer);
        f(root->right, answer);
    }
    string smallestFromLeaf(TreeNode* root) {
        string answer;
        if (root == NULL)
            return answer;
        f(root, answer);
        sort(res.begin(), res.end());
        return res[0];
    }
};