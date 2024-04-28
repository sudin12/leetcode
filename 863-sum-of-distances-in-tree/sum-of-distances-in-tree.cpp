
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        vector<int> count(n, 1), ans(n, 0);
        
        // Build the tree
        for (const auto& edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        
        // Calculate count and answer for each node
        dfs(0, -1, tree, count, ans);
        dfs2(0, -1, tree, count, ans, n);
        
        return ans;
    }
    
    // DFS to calculate count and answer for each node
    void dfs(int node, int parent, const vector<vector<int>>& tree, vector<int>& count, vector<int>& ans) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            dfs(child, node, tree, count, ans);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }
    
    // DFS to calculate the answer for each node based on the parent node's answer
    void dfs2(int node, int parent, const vector<vector<int>>& tree, const vector<int>& count, vector<int>& ans, int n) {
        for (int child : tree[node]) {
            if (child == parent) continue;
            ans[child] = ans[node] - count[child] + n - count[child];
            dfs2(child, node, tree, count, ans, n);
        }
    }
};