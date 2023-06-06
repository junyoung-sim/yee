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

int fibonacci(int n) {
    if(n == 0)
        return 0;
    else if(n == 1 || n == 2)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N; std::cin >> N;
    std::cout << fibonacci(N) << "\n";

    return 0;
}