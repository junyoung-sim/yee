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

int white = 0;
int blue = 0;

void solve(std::vector<std::vector<int>> &v, int N, int r, int c) {
    int sum = 0;
    for(int i = r; i < r + N; i++)
        for(int j = c; j < c + N; j++)
            sum += v[i][j];
    
    if(sum == 0) { white++; return; }
    if(sum == N*N) { blue++; return; }

    solve(v, N/2, r, c);
    solve(v, N/2, r, c + N/2);
    solve(v, N/2, r + N/2, c);
    solve(v, N/2, r + N/2, c + N/2);
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

    std::cout << white << "\n";
    std::cout << blue << "\n";

    return 0;
}