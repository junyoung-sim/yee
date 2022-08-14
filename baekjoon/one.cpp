
#include <cstdlib>
#include <iostream>

int main()
{
    unsigned int n;
    while(std::cin >> n) {
        unsigned int k = 1;
        unsigned int num = 0;
        while(true) {
            num = 1 + num * 10;
            num %= n;

            if(num == 0) {
                std::cout << k << "\n";
                break;
            }

            k++;
        }
    }
    return 0;
}
