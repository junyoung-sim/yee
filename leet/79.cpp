class Solution {
public:
    int N, M;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};
    vector<vector<bool>> visit;
    bool search(vector<vector<char>> &board, string word, int i, int j, int k) {
        if(board[i][j] != word[k]) return false;
        if(k == word.length() - 1) return true;
        for(int n = 0; n < 4; n++) {
            int pr = i + dr[n];
            int pc = j + dc[n];
            if(pr >= 0 && pr < N && pc >= 0 && pc < M && !visit[pr][pc]) {
                visit[pr][pc] = true;
                if(search(board, word, pr, pc, k+1)) return true;
                visit[pr][pc] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word) {
        N = board.size();
        M = board[0].size();
        visit.resize(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                visit[i][j] = true;
                if(search(board, word, i, j, 0)) return true;
                visit[i][j] = false;
            }
        }
        return false;
    }
};
