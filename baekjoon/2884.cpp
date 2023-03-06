#include <iostream>
#include <cstdlib>

int main()
{
    int H, M;
    std::cin >> H >> M;

    int k = 45;

    M -= k;
    if(M < 0) {
        H--;
        M = 60 - abs(M);
    }
    if(H < 0)
        H  = 24 - abs(H);

    std::cout << H << " " << M << "\n";

    return 0;
}