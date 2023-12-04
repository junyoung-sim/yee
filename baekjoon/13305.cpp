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

    long long int N;
    std::cin >> N;

    std::vector<long long int> d(N, 0);
    std::vector<long long int> r(N, 0);

    for(long long int i = 1; i < N; i++)
        std::cin >> d[i];
    for(long long int i = 0; i < N; i++)
        std::cin >> r[i];
    
    long long int cost = r[0];
    long long int total = r[0] * d[1];
    for(long long int i = 1; i < N; i++) {
        if(r[i] < cost)
            cost = r[i];
        total += cost * d[i+1];
    }
    std::cout << total << "\n";

    return 0;
}