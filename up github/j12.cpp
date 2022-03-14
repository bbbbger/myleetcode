#include<vector>
using namespace std;
#include<string>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->len = word.size();
        if (len == 0)return false;
        this->rows = board.size();
        if (rows == 0)return false;
        else this->cols = board[0].size();
        bool ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, word, i, j, 0))return true;
            }
        }
        return false;
    }
private:
    int rows, cols;
    int len;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k)
    {
        if (i >= rows || i < 0 || j >= cols || j < 0 || k >= len || board[i][j] != word[k])return false;
        if (k == len - 1)return true;
        board[i][j] = '\0';
        bool ret = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) ||
            dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j - 1, k + 1);
        board[i][j] = word[k];
        return ret;
    }
};