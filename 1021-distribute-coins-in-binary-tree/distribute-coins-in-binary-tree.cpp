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
    int distributeCoins(TreeNode* root) {
        int totalMoves = 0;
        dfs(root, totalMoves);
        return totalMoves;
    }
    
private:
    // Helper function to perform DFS and calculate excess coins
    int dfs(TreeNode* node, int& totalMoves) {
        if (!node) return 0;
        
        int leftExcess = dfs(node->left, totalMoves);
        int rightExcess = dfs(node->right, totalMoves);
        
        // Calculate the current node's excess coins
        int currentExcess = node->val - 1 + leftExcess + rightExcess;
        
        // Accumulate the total moves required
        totalMoves += abs(leftExcess) + abs(rightExcess);
        
        return currentExcess;
    }
};