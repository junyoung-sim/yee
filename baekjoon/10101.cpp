#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;

    if(a + b + c == 180) {
        if(a == b && b == c)
            std::cout << "Equilateral\n";
        else if(a != b && b != c && a != c)
            std::cout << "Scalene\n";
        else
            std::cout << "Isosceles\n";
    }
    else
        std::cout << "Error\n";

    return 0;
}