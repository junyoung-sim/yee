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
    while(std::cin >> a >> b >> c && a != 0) {
        int max_len = std::max(a, std::max(b, c));
        if(max_len == a && a < b + c || max_len == b && b < a + c || max_len == c && c < a + b) {
            if(a == b && b == c)
                std::cout << "Equilateral\n";
            else if(a != b && b != c && a != c)
                std::cout << "Scalene\n";
            else
                std::cout << "Isosceles\n";
        }
        else
            std::cout << "Invalid\n";
    }

    return 0;
}