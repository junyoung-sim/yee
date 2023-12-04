
#include <iostream>

int main()
{
    unsigned int A, B;
    std::cin >> A >> B;

    unsigned int gcd = 0;
    for(unsigned int i = 1; i <= std::min(A, B); i++) {
        if(A % i == 0 && B % i == 0 && i > gcd) gcd = i;
    }

    std::cout << gcd << "\n";
    std::cout << gcd * (A / gcd) * (B / gcd) << "\n";

    return 0;
}
