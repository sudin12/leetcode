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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> forest;
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        
        dfs(root, true, to_delete_set, forest);
        return forest;
    }
    
private:
    TreeNode* dfs(TreeNode* node, bool is_root, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        
        bool should_delete = to_delete_set.count(node->val);
        
        if (is_root && !should_delete) {
            forest.push_back(node);
        }
        
        node->left = dfs(node->left, should_delete, to_delete_set, forest);
        node->right = dfs(node->right, should_delete, to_delete_set, forest);
        
        return should_delete ? nullptr : node;
    }
};