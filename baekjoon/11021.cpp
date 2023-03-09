#include <iostream>
#include <cstdio>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    int ans[T];
    int a, b;
    for(int t = 0; t < T; t++) {
        std::cin >> a >> b;
        ans[t] = a + b;
    }

    for(int t = 0; t < T; t++)
        std::cout << "Case #" << t+1 << ": " << ans[t] << "\n";

    return 0;
}