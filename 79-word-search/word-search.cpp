class Solution {
public:
bool find(vector<vector<char>>& board, int idx,int row, int col, string& word) {
if (idx == word.length()) return true;
 if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
if (board[row][col] != word[idx])  return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool found =
            find(board, idx + 1, row + 1, col, word) ||
            find(board, idx + 1, row - 1, col, word) ||
            find(board, idx + 1, row, col + 1, word) ||
            find(board, idx + 1, row, col - 1, word);

        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (find(board, 0, i, j, word))
                    return true;
            }
        }

        return false;
    }
};