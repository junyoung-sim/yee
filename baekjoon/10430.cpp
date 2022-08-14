
#include <cstdlib>
#include <iostream>

int main()
{
    unsigned int A, B, C;
    std::cin >> A >> B >> C;

    std::cout << (A + B) % C << "\n";
    std::cout << ((A % C) + (B % C)) % C << "\n";
    std::cout << (A * B) % C << "\n";
    std::cout << ((A % C) * (B % C)) % C << "\n";

    return 0;
}
