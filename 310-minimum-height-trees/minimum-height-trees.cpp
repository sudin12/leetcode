class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0}; // Only one node, return it as MHT

        vector<int> degrees(n, 0);      // Degree of each node
        vector<vector<int>> adjList(n); // Adjacency list representing the tree

        // Construct the adjacency list and calculate degrees
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }

        // Create a queue for BFS starting from leaves
        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                leaves.push(i);
            }
        }

        // Perform BFS to trim the leaves layer by layer until MHTs are found
        while (n > 2) {
            int numLeaves = leaves.size();
            n -= numLeaves;
            for (int i = 0; i < numLeaves; ++i) {
                int leaf = leaves.front();
                leaves.pop();
                for (int neighbor : adjList[leaf]) {
                    if (--degrees[neighbor] == 1) {
                        leaves.push(neighbor);
                    }
                }
            }
        }

        // Now the remaining nodes in the queue are potential MHT roots
        vector<int> result;
        while (!leaves.empty()) {
            result.push_back(leaves.front());
            leaves.pop();
        }

        return result;
    }
};