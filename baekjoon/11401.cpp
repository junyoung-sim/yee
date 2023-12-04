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

long long int solve(long long int a, long long int n) {
    if(n == 1)
        return a % MOD;
    long long int x = solve(a, n/2) % MOD;
    if(n % 2 == 0)
        return x * x % MOD;
    else
        return x * x % MOD * a % MOD;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int N, K;
    std::cin >> N >> K;

    // A = n(n-1)(n-2) ... (n-k+1)
    long long int A = 1;
    for(long long int i = N; i >= N-K+1; i--) A = (A * i) % MOD;

    // B = k!
    long long int B = 1;
    for(long long int i = 1; i <= K; i++) B = (B * i) % MOD;

    std::cout << A * solve(B, MOD-2) % MOD << "\n";

    return 0;
}