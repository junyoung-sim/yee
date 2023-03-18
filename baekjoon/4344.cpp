#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cout.precision(3);
    std::cout << std::fixed;

    int T;
    std::cin >> T;

    int test[1001];
    double ans[T];

    for(int t = 0; t < T; t++) {
        std::cin >> test[0];
        int mean = 0;
        for(int i = 1; i <= test[0]; i++) {
            std::cin >> test[i];
            mean += test[i];
        }
        mean /= test[0];

        int count = 0;
        for(int i = 1; i <= test[0]; i++)
            count += (test[i] > mean);
        ans[t] = (double)count * 100 / test[0];
    }

    for(int t = 0; t < T; t++)
        std::cout << ans[t] << "%\n";

    return 0;
}