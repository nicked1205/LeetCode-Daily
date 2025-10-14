class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for (auto dir : directions) {
            int nr = rMove + dir[0];
            int nc = cMove + dir[1];
            if (nc >= 8 || nr >= 8 || nc < 0 || nr < 0) continue;
            if (color == 'W' && board[nr][nc] == 'B') {
                if (checkDirection(board, dir, nr, nc, 'B')) return true;
            } else if (color == 'B' && board[nr][nc] == 'W') {
                if (checkDirection(board, dir, nr, nc, 'W')) return true;
            }
        }
        return false;
    }

    bool checkDirection(vector<vector<char>>& board, vector<int> dir, int x, int y, char color) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (ny >= 8 || nx >= 8 || ny < 0 || nx < 0) return false;
        while (board[nx][ny] == color) {
            nx += dir[0];
            ny += dir[1];
            if (ny >= 8 || nx >= 8 || ny < 0 || nx < 0) return false;
        }
        if ((color == 'B' && board[nx][ny] == 'W') || (color == 'W' && board[nx][ny] == 'B')) return true;
        return false;
    }
};