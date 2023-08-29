#include <bits/stdc++.h>
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

std::vector<std::vector<int>> matmul(std::vector<std::vector<int>> &x, std::vector<std::vector<int>> &y) {
    int N = x.size(), M = x[0].size(), K = y[0].size();
    std::vector<std::vector<int>> out(N, std::vector<int>(K));
    for(int n = 0; n < N; n++) {
        for(int k = 0; k < K; k++) {
            int sum = 0;
            for(int m = 0; m < M; m++)
                sum += x[n][m] * y[m][k];
            out[n][k] = sum;
        }
    }
    return out;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M, K;

    std::cin >> N >> M;
    std::vector<std::vector<int>> a(N, std::vector<int>(M));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            std::cin >> a[i][j];
    
    std::cin >> M >> K;
    std::vector<std::vector<int>> b(M, std::vector<int>(K));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < K; j++)
            std::cin >> b[i][j];
    
    std::vector<std::vector<int>> out = matmul(a, b);
    for(int i = 0; i < out.size(); i++) {
        for(int j = 0; j < out[i].size(); j++)
            std::cout << out[i][j] << " ";
        std::cout << "\n";
    }

    return 0;
}