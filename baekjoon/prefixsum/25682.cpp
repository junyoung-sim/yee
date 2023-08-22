#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, K;
    std::cin >> N >> M >> K;

    int v[N+1][M+1];
    int B[N+1][M+1];
    int W[N+1][M+1];

    std::string row;
    for(int i = 1; i <= N; i++) {
        std::cin >> row;
        for(int j = 1; j <= M; j++)
            v[i][j] = (row[j-1] == 'W');
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(i % 2 == j % 2) {
                B[i][j] = (v[i][j] != 0);
                W[i][j] = (v[i][j] != 1);
            }
            else {
                B[i][j] = (v[i][j] != 1);
                W[i][j] = (v[i][j] != 0);
            }

            B[i][j] += B[i][j-1] + B[i-1][j] - B[i-1][j-1];
            W[i][j] += W[i][j-1] + W[i-1][j] - W[i-1][j-1];
        }
    }

    int ans = RAND_MAX;
    for(int i = K; i <= N; i++) {
        for(int j = K; j <= M; j++) {
            ans = std::min(B[i][j] - B[i][j-K] - B[i-K][j] + B[i-K][j-K], ans);
            ans = std::min(W[i][j] - W[i][j-K] - W[i-K][j] + W[i-K][j-K], ans);
        }
    }

    std::cout << ans << "\n";

    return 0;
}