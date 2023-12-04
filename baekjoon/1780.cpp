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

int count[3] = {0, 0, 0}; // -1, 0, 1

bool check(std::vector<std::vector<int>> &v, int N, int r, int c) {
    for(int i = r; i < r + N; i++)
        for(int j = c; j < c + N; j++)
            if(v[i][j] != v[r][c]) return false;
    return true;
}

void solve(std::vector<std::vector<int>> &v, int N, int r, int c) {
    bool valid = check(v, N, r, c);
    if(valid && v[r][c] == -1) { count[0]++; return; }
    if(valid && v[r][c] == 0) { count[1]++; return; }
    if(valid && v[r][c] == 1) { count[2]++; return; }

    solve(v, N/3, r, c);
    solve(v, N/3, r, c + N/3);
    solve(v, N/3, r, c + N*2/3);

    solve(v, N/3, r + N/3, c);
    solve(v, N/3, r + N/3, c + N/3);
    solve(v, N/3, r + N/3, c + N*2/3);

    solve(v, N/3, r + N*2/3, c);
    solve(v, N/3, r + N*2/3, c + N/3);
    solve(v, N/3, r + N*2/3, c + N*2/3);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::vector<int>> v(N, std::vector<int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> v[i][j];
    
    solve(v, N, 0, 0);

    std::cout << count[0] << "\n";
    std::cout << count[1] << "\n";
    std::cout << count[2] << "\n";

    return 0;
}