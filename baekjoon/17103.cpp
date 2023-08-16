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
    
    std::vector<bool> prime(1000001, true); // erastothenes sieve
    prime[1] = false;
    for(int i = 2; i <= 1000000; i++) {
        if(prime[i]) {
            for(int k = i+i; k <= 1000000; k += i)
                prime[k] = false;
        }
    }

    int T;
    std::cin >> T;

    int N;
    for(int t = 1; t <= T; t++) {
        std::cin >> N;
        int limit = N;
        int count = 0;
        for(int i = 2; i < limit; i++) {
            if(prime[i] && prime[N-i]) {
                count++;
                limit = N-i; // prevent counting duplicate Goldbach partitions
            }
        }
        std::cout << count << "\n";
    }

    return 0;
}