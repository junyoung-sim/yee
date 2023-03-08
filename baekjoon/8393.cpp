#include <iostream>
#include <cstdlib>

int main()
{
    int N;
    std::cin >> N;

    int ans = 0;
    for(int i = 1; i <= N; i++) ans += i;

    std::cout << ans << "\n";

    return 0;
}