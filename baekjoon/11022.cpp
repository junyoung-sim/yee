#include <iostream>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    int a, b;
    for(int t = 1; t <= T; t++) {
        std::cin >> a >> b;
        std::cout << "Case #" << t << ": " << a << " + " << b << " = " << a + b << "\n";
    }

    return 0;
}