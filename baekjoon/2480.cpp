#include <iostream>
#include <cstdlib>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;

    if(A == B && B == C)
        std::cout << 10000 + A * 1000 << "\n";
    else if(A == B || A == C && B != C)
        std::cout << 1000 + A * 100 << "\n";
    else if(B == C && A != C)
        std::cout << 1000 + B * 100 << "\n";
    else
        std::cout << std::max(A, std::max(B, C)) * 100 << "\n";

    return 0;
}