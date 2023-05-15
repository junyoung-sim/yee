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
    
    std::vector<bool> is_prime(246913, true); 
    is_prime[1] = false;
    for(int i = 2; i <= 246912; i++) {
        if(is_prime[i]) {
            for(int k = i+i; k <= 246912; k += i)
                is_prime[k] = false;
        }
    }

    int N;
    while(std::cin >> N && N != 0) {
        int count = 0;
        for(int n = N+1; n <= N*2; n++)
            count += is_prime[n];
        std::cout << count << "\n";
    }

    return 0;
}