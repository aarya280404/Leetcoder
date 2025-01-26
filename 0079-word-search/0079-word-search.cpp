class Solution {
public:
    bool func(int i, int j, int n, int m, vector<vector<char>>& board, string& path, vector<vector<int>>& vis, string& word) {
        if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || board[i][j] != word[path.size()]) {
            return false;
        }

        path += board[i][j];
        vis[i][j] = 1;

        // Check if the word is found
        if (path.size() == word.size()) {
            vis[i][j] = 0;
            path.pop_back();
            return true;
        }

        // Explore all directions
        bool found = func(i + 1, j, n, m, board, path, vis, word) ||
                     func(i - 1, j, n, m, board, path, vis, word) ||
                     func(i, j + 1, n, m, board, path, vis, word) ||
                     func(i, j - 1, n, m, board, path, vis, word);

        vis[i][j] = 0;
        path.pop_back();
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Try starting from every cell
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string path;
                if (func(i, j, n, m, board, path, vis, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
