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

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> v(N+1, std::vector<int>(N+1, 0));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            std::cin >> v[i][j];
            v[i][j] += v[i][j-1] + v[i-1][j] - v[i-1][j-1];
        }
    }

    while(M--) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1] << "\n";
    }

    return 0;
}