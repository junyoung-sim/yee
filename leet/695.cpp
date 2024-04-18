class Solution {
public:
    int N, M;
    vector<vector<bool>> visit;
    vector<vector<int>> *graph;
    
    int count = 1;
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int i, int j) {
        for(int n = 0; n < 4; n++) {
            int pr = i + dr[n];
            int pc = j + dc[n];
            if(pr >= 0 && pr < N && pc >= 0 && pc < M && (*graph)[pr][pc] && !visit[pr][pc]) {
                visit[pr][pc] = true; count++;
                dfs(pr, pc);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        N = grid.size();
        M = grid[0].size();

        graph = &grid;
        visit.resize(N, vector<bool>(M, false));

        int ans = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] && !visit[i][j]) {
                    visit[i][j] = true;
                    dfs(i, j);
                    ans = max(count, ans);
                    count = 1;
                }
            }
        }
        return ans;
    }
};
