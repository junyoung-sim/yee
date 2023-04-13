#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

struct Set {
    int A = 0;
    int B = 0;
};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N, M;
    std::cin >> N >> M;

    int x;
    std::map<int, Set> val;
    for(int i = 0; i < N; i++) {
        std::cin >> x;
        val[x].A = 1;
    }
    for(int j = 0; j < M; j++) {
        std::cin >> x;
        val[x].B = 1;
    }

    int ans = 0;
    for(auto v: val)
        ans += (v.second.A && !v.second.B || !v.second.A && v.second.B);
    std::cout << ans << "\n";

    return 0;
}