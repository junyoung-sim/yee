#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main()
{
    std::vector<int> r(43, 0);

    int n;
    int count = 0;
    while(std::cin >> n) {
        if(r[n % 42] == 0) {
            r[n % 42] = 1;
            count++;
        }
    }

    std::cout << count << "\n";

    return 0;
}