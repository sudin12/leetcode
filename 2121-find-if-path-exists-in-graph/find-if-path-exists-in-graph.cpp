
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        unordered_set<int> visited;
        return dfs(graph, visited, source, destination);
    }
    
    bool dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int source, int destination) {
        if (source == destination) return true;
        visited.insert(source);
        for (int neighbor : graph[source]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfs(graph, visited, neighbor, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
};