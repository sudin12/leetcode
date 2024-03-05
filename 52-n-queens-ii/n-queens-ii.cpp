class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        solveNQueens(board, 0, count);
        return count;
    }
    
    void solveNQueens(vector<string>& board, int row, int& count) {
        if (row == board.size()) {
            count++;
            return;
        }
        
        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                solveNQueens(board, row + 1, count);
                board[row][col] = '.';
            }
        }
    }
    
    bool isValid(const vector<string>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
};