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

    int N, K; std::cin >> N >> K;

    int v[N+1]; v[0] = 0;
    for(int i = 1; i <= N; i++) {
        std::cin >> v[i];
        if(i > 0)
            v[i] += v[i-1];
    }

    int ans = -RAND_MAX;
    for(int i = K; i <= N; i++)
        ans = std::max(v[i] - v[i-K], ans);

    std::cout << ans << "\n";

    return 0;
}