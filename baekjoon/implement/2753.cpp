#include <iostream>
#include <cstdlib>

int main()
{
    int year;
    std::cin >> year;

    std::cout << (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) << "\n";

    return 0;
}