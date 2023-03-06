#include <iostream>

int main()
{
    double A, B;
    std::cin >> A >> B;

    std::cout.precision(12); // set precision to 9 digits
    std::cout << std::fixed; // apply that precision only to the decimals

    std::cout << A / B << "\n";
    
    return 0;
}
