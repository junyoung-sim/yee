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
    
    int N;
    std::cin >> N;

    std::vector<bool> prime(N+1, true);
    prime[1] = false;

    for(int i = 2; i <= N; i++) {
        if(prime[i]) {
            for(int k = i+i; k <= N; k += i)
                prime[k] = false;
        }
    }

    for(int i = 1; i <= N; i++)
        std::cout << i << ": " << prime[i] << "\n";

    return 0;
}