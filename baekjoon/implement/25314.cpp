#include <iostream>
#include <cstdlib>

int main()
{
    int N;

    for(int i = 0; i < N / 4; i++)
        std::cout << "long ";
    std::cout << "int\n";

    return 0;
}