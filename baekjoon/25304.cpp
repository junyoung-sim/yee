#include <iostream>
#include <cstdlib>

int main()
{
    int X; std::cin >> X;
    int N; std::cin >> N;

    int a, b;
    int T = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> a >> b;
        T += a * b;
    }

    if(T == X) std::cout << "Yes\n";
    else std::cout << "No\n";

    return 0;
}