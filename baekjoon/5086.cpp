#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int a = -1, b = -1;

    while(std::cin >> a >> b && a != 0 && b != 0) {
        if(b % a == 0)
            std::cout << "factor\n";
        else if(a % b == 0)
            std::cout << "multiple\n";
        else
            std::cout << "neither\n";
    }

    return 0;
}