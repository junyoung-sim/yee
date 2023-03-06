#include <iostream>
#include <cstdlib>

int main()
{
    int H, M;
    std::cin >> H >> M;

    int A;
    std::cin >> A;

    H += A / 60;
    M += A % 60;

    if(M >= 60) {
        H++;
        M -= 60;
    }

    if(H >= 24) H -= 24;

    std::cout << H << " " << M << "\n";

    return 0;
}