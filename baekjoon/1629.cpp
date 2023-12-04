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

long long int solve(long long int A, long long int B, long long int C) {
    if(B == 1)
        return A % C;
    long long int x = solve(A, B/2, C) % C;
    if(B % 2 == 0)
        return x * x % C;
    else
        return x * x % C * A % C;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << solve(A, B, C) << "\n";

    return 0;
}