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

struct Line {
    int A, B;
    Line(int a, int b): A(a), B(b) {}
};

bool cmp(Line &x, Line &y) {
    return x.A < y.A;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;

    int A, B;
    std::vector<Line> lines;
    for(int i = 0; i < N; i++) {
        std::cin >> A >> B;
        lines.push_back(Line(A, B));
    }

    std::sort(lines.begin(), lines.end(), cmp);
    
    int lis = 1; // longest increasing sequence
    std::vector<int> dp(N, 1);
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++)
            if(lines[j].B < lines[i].B && dp[j] >= dp[i]) dp[i] = dp[j] + 1;
        lis = std::max(dp[i], lis);
    }

    std::cout << N - lis << "\n";

    return 0;
}