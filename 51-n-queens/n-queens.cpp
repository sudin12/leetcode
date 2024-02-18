class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        solveNQueensHelper(result, board, 0, n);

        return result;
    }

private: 
    void solveNQueensHelper(vector<vector<string>>& result, vector<string>& board, int row, int n){
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; ++col){
            if(isValid(board, row, col, n)){
               board[row][col] = 'Q';
               solveNQueensHelper(result, board, row + 1, n);
               board[row][col] = '.';
            }
        }
    }

    bool isValid(const vector<string>& board, int row, int col, int n){
            //Check if there's a queen in the same column.
            for(int i = 0; i < row; i++){
                if(board[i][col] == 'Q'){
                    return false;
                }
            }

            //Check upper left diagonal
            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
                   if(board[i][j] == 'Q'){
                    return false;
                }
            }

            //Check upper right diagonal
            for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }

         return true;
     }
};