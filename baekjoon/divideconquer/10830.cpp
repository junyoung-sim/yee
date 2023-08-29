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

std::vector<std::vector<long long int>> matmul(std::vector<std::vector<long long int>> &x, std::vector<std::vector<long long int>> &y) {
    int N = x.size(), M = x[0].size(), K = y[0].size();
    std::vector<std::vector<long long int>> out(N, std::vector<long long int>(K));
    for(int n = 0; n < N; n++) {
        for(int k = 0; k < K; k++) {
            for(int m = 0; m < M; m++)
                out[n][k] += x[n][m] * y[m][k];
            out[n][k] %= 1000;
        }
    }
    return out;
}

std::vector<std::vector<long long int>> solve(std::vector<std::vector<long long int>> &A, long long int B) {
    if(B == 1)
        return A;
    std::vector<std::vector<long long int>> x = solve(A, B/2);
    if(B % 2 == 0)
        return matmul(x, x);
    else {
        std::vector<std::vector<long long int>> y = matmul(x, x);
        return matmul(y, A);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int N, B;
    std::cin >> N >> B;

    std::vector<std::vector<long long int>> A(N, std::vector<long long int>(N));
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            std::cin >> A[i][j];
    
    A = solve(A, B);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            std::cout << A[i][j] % 1000 << " ";
        std::cout << "\n";
    }

    return 0;
}