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

    int N, M; std::cin >> N >> M;

    int sum[N+1]; sum[0] = 0;
    for(int i = 1; i <= N; i++) {
        std::cin >> sum[i];
        if(i > 0)
            sum[i] += sum[i-1];
    }

    while(M--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << sum[b] - sum[a-1] << "\n";
    }

    return 0;
}