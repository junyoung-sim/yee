#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cout.precision(12);
    std::cout << std::fixed;

    int N;
    std::cin >> N;

    int v[N];
    int M = -RAND_MAX;
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        M = std::max(v[i], M);
    }

    double mean = 0.0;
    for(int i = 0; i < N; i++)
        mean += (double)v[i] / M * 100;
    mean /= N;

    std::cout << mean << "\n";

    return 0;
}