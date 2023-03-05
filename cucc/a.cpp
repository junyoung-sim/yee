#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N, A, B;
    std::cin >> N >> A >> B;

    int t = 0;
    int n = 0, a = A;
    while(n < N) {
        n += a + t / B;
        t++;
    }

    std::cout << t << "\n";

    return 0;
}