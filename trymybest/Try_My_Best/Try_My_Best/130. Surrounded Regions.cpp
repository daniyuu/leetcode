#include <iostream>
#include <queue>

using namespace std;

class Solution {
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
    
    void bfs(int x, int y, vector<vector<char>> &board){
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;
        
        q.push(make_pair(x, y));
        board[x][y] = '+';
        
        while (!q.empty()) {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'O') {
                    board[nx][ny] = '+';
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>> &board){
        if (board.empty() || board[0].empty()) {
            return;
        }
        
        int n = board.size();
        int m = board[0].size();
        
        if (n <= 2 || m <= 2) {
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                bfs(i, 0, board);
            }
            if (board[i][m - 1] == 'O') {
                bfs(i, m - 1, board);
            }
        }
        
        
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                bfs(0, j, board);
            }
            if (board[n -1][j] == 'O') {
                bfs(n - 1, j, board);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '+') {
                    board[i][j] = 'O';
                }else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
