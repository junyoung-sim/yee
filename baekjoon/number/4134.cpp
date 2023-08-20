#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

bool prime(long long int x) {
    if(x <= 1)
        return false;
    for(long long int i = 2; i <= sqrt(x); i++)
        if(x % i == 0)
            return false;
    return true;
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    long long int N;
    for(int t = 0; t < T; t++) {
        std::cin >> N;
        while(!prime(N)) N++;
        
        std::cout << N << "\n";
    }

    return 0;
}