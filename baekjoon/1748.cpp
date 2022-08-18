
#include <iostream>
#include <cmath>

int main()
{
    int N; std::cin >> N;

    int k = 1;
    int digits = 0;

    while(true) {
        if(N >= (int)pow(10,k))
            digits += k * ((int)pow(10,k) - (int)pow(10,k-1));
        else {
            digits += k * (N - (int)pow(10,k-1) + 1);
            break;
        }
        k++;
    }

    std::cout << digits << "\n";

    return 0;
}
