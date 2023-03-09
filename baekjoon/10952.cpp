#include <iostream>
#include <cstdlib>
#include <cstdio>

int main()
{
    int a, b;
    while(!(std::cin >> a >> b).eof())
        std::cout << a + b << "\n";
    return 0;
}