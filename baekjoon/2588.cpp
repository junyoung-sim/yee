#include <iostream>
#include <string>

int main()
{
    int A; std::cin >> A;
    int B; std::cin >> B;
    
    std::string strB = std::to_string(B);
    for(int i = strB.length() - 1; i >= 0; i--)
        std::cout << (strB[i] - '0') * A << "\n";
    std::cout << A * B << "\n";
    
    return 0;
}
