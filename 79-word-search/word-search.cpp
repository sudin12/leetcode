class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*'; // Mark the cell as visited
        
        bool found = dfs(board, word, idx + 1, i + 1, j) ||
                     dfs(board, word, idx + 1, i - 1, j) ||
                     dfs(board, word, idx + 1, i, j + 1) ||
                     dfs(board, word, idx + 1, i, j - 1);
        
        board[i][j] = temp; // Restore the cell
        
        return found;
    }
};