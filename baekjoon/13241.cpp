#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>

long long int gcd(int A, int B) {
    if(B == 0)
        return A;
    else
        return gcd(B, A % B);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    long long int A, B;
    std::cin >> A >> B;
    std::cout << A * B / gcd(A, B) << "\n";

    return 0;
}