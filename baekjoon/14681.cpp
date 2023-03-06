#include <iostream>
#include <cstdlib>

int main()
{
    int x; std::cin >> x;
    int y; std::cin >> y;

    if(x > 0 && y > 0) std::cout << "1\n";
    else if(x < 0 && y > 0) std::cout << "2\n";
    else if(x < 0 && y < 0) std::cout << "3\n";
    else std::cout << "4\n";

    return 0;
}