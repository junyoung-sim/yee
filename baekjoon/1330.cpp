#include <iostream>
#include <cstdlib>

int main()
{
    int A, B;
    std::cin >> A >> B;

    if(A > B) std::cout << ">\n";
    else if(A < B) std::cout << "<\n";
    else std::cout << "==\n"; 

    return 0;
}