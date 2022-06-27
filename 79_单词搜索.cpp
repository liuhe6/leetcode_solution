class Solution {
public:
    bool exist(vector<vector<char>>& board, string str) {
        for (int i = 0; i < board.size(); i ++ )
            for (int j = 0; j < board[i].size(); j ++ )
                if (dfs(board, str, 0, i, j))
                    return true;
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &str, int u, int x, int y) {
        if (board[x][y] != str[u]) return false;
        if (u == str.size() - 1) return true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char t = board[x][y];
        board[x][y] = '*';
        for (int i = 0; i < 4; i ++ ) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < board.size() && b >= 0 && b < board[a].size()) {
                if (dfs(board, str, u + 1, a, b)) return true;
            }
        }
        board[x][y] = t;
        return false;
    }
};
