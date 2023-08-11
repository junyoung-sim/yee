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

    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());

    int ans = v[0];
    for(int i = 1; i < N; i++) {
        v[i] += v[i-1];
        ans += v[i];
    }

    std::cout << ans << "\n";

    return 0;
}