#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int A1, B1;
    int A2, B2;

    std::cin >> A1 >> B1;
    std::cin >> A2 >> B2;

    int A = A1 * B2 + A2 * B1;
    int B = B1 * B2;

    std::cout << A / gcd(A, B) << " " << B / gcd(A, B) << "\n";

    return 0;
}