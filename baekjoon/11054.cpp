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

    int N; std::cin >> N;

    int v[N], u[N], d[N];
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        u[i] = d[i] = 1;
    }

    for(int i = 1; i < N; i++)
        for(int j = 0; j < i; j++)
            if(v[j] < v[i] && u[j] >= u[i]) u[i] = u[j] + 1;
    
    for(int i = N-2; i >= 0; i--)
        for(int j = i+1; j < N; j++)
            if(v[i] > v[j] && d[j] >= d[i]) d[i] = d[j] + 1;
    
    int ans = 1;
    for(int i = 0; i < N; i++)
        ans = std::max(u[i] + d[i] - 1, ans);
    
    std::cout << ans << "\n";

    return 0;
}