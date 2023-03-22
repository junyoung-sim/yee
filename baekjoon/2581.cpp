#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int M, N;
    std::cin >> M >> N;

    std::vector<int> prime(N+1, 1);
    prime[1] = 0;

    for(int i = 2; i <= N; i++)
        for(int k = i+i; k <= N; k += i)
            prime[k] = 0;

    int sum = 0;
    int smallest = RAND_MAX;

    for(int i = M; i <= N; i++) {
        if(prime[i]) {
            sum += i;
            smallest = std::min(smallest, i);
        }
    }

    if(sum != 0)
        std::cout << sum << "\n" << smallest << "\n";
    else
        std::cout << "-1\n";

    return 0;
}