#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    long long int n;
    std::cin >> n;

    std::cout << n*(n-1)*(n-2)/6 << "\n3";

    return 0;
}