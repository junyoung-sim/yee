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

    int N, K;
    std::cin >> N >> K;

    int v[N];
    for(int i = 0; i < N; i++)
        std::cin >> v[i];

    int ans = 0;
    while(K) {
        int i = -1;
        while(++i < N && K / v[i]);

        ans += K / v[i-1];
        K %= v[i-1];
    }

    std::cout << ans << "\n";

    return 0;
}