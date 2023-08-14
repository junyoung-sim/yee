
#include <iostream>
#include <vector>

int main()
{
    unsigned int a, b;
    std::cin >> a >> b;

    std::vector<bool> prime(b, true); // 1 ~ b
    prime[0] = false;

    unsigned int i = 1;
    while(i < b) {
        unsigned int num = i + 1;
        for(unsigned int k = i + num; k < b; k += num) prime[k] = false;

        while(++i < b && !prime[i]);
    }

    for(unsigned int k = 0; k < b; k++)
        if(prime[k] && k+1 >= a) std::cout << k + 1 << "\n";

    return 0;
}
