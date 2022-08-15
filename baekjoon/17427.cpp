
#include <iostream>

int main()
{
    unsigned int T;
    std::cin >> T;

    int N;
    for(unsigned int t = 0; t < T; t++) {
        std::cin >> N;
        unsigned long long int g = 0;
        for(unsigned int i = 1; i <= N; i++)
            g += i * (N / i);
        std::cout << g << "\n";
    }

    return 0;
}
