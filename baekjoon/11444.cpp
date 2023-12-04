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

#define MOD 1000000007

std::vector<std::vector<long long int>> matmul(std::vector<std::vector<long long int>> &x, std::vector<std::vector<long long int>> &y) {
    long long int N = x.size(), M = x[0].size(), K = y[0].size();
    std::vector<std::vector<long long int>> out(N, std::vector<long long int>(K));
    for(long long int n = 0; n < N; n++) {
        for(long long int k = 0; k < K; k++) {
            for(long long int m = 0; m < M; m++)
                out[n][k] += x[n][m] * y[m][k];
            out[n][k] %= MOD;
        }
    }
    return out;
}

std::vector<std::vector<long long int>> matexp(std::vector<std::vector<long long int>> &mat, long long int N) {
    if(N == 1)
        return mat;
    std::vector<std::vector<long long int>> half = matexp(mat, N/2);
    std::vector<std::vector<long long int>> merge = matmul(half, half);
    if(N % 2 == 0)
        return merge;
    else
        return matmul(merge, mat);
}

long long int fibonacci(long long int N) {
    std::vector<std::vector<long long int>> base = {{1},{1},{0}};
    std::vector<std::vector<long long int>> fibo = {{1,1,0},{1,0,0},{0,1,0}};

    if(N <= 2)
        return base[2-N][0];

    fibo = matexp(fibo, N-2);
    base = matmul(fibo, base);
    
    return base[0][0] % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int N; std::cin >> N;
    std::cout << fibonacci(N) << "\n";

    return 0;
}