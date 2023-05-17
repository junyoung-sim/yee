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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<long long int> factorial(n+1, 1);
    for(int i = 1; i <= n; i++)
        factorial[i] = factorial[i-1] * i;

    std::cout << factorial[n] / (factorial[k] * factorial[n-k]) << "\n";

    return 0;
}