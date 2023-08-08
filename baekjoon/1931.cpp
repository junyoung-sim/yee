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

struct Meet {
    int start;
    int end;
};

bool cmp(Meet &x, Meet &y) {
    if(x.start == y.start)
        return x.end < y.end;
    return x.start < y.start;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<Meet> meet(N);
    for(int i = 0; i < N; i++)
        std::cin >> meet[i].start >> meet[i].end;

    std::sort(meet.begin(), meet.end(), cmp);

    int k = 0;
    std::vector<int> dp(N, 1);
    for(int i = 1; i < N; i++) {
        dp[i] = dp[i-1];
        if(meet[k].end <= meet[i].start) {
            dp[i] = dp[k] + 1;
            k = i;
            continue;
        }
        if(meet[i].end < meet[k].end) k = i;
    }

    std::cout << dp[N-1] << "\n";

    return 0;
}