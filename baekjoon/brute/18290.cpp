#include <iostream>
#include <vector>

int N, M, K;
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> step;

int ans = -10001;

void func(int i, int j, int sum, int k) {
    if(k == K) {
        ans = std::max(sum, ans);
        return;
    }

    step[i][j] = 1;

    int r[4] = {i-1, i-1, i+1, i+1};
    int c[4] = {j-1, j+1, j-1, j+1};

    for(int n = 0; n < 4; n++) {
        if(r[n] >= 0 && r[n] < N && c[n] >= 0 && c[n] < M && step[r[n]][c[n]] == 0) {
            func(r[n], c[n], sum + map[r[n]][c[n]], k+1);
            step[r[n]][c[n]] = 0;
        }
    }

    step[i][j] = 0;
}

int main()
{
    std::cin >> N >> M >> K;
    map.resize(N, std::vector<int>(M));
    step.resize(N, std::vector<int>(M));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> map[i][j];
            step[i][j] = 0;
        }
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            func(i, j, map[i][j], 1);

    std::cout << ans << "\n";

    return 0;
}
