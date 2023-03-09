#include <iostream>
#include <cstdlib>

int main()
{
    int N;
    std::cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++)
            std::cout << "*";
        std::cout << "\n";
    }

    return 0;
}