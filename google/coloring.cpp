#include <iostream>

int main()
{
    int T; std::cin >> T;

    for(int t = 1; t <= T; t++) {
        int N; std::cin >> N;
        int ans = 1+(N-1)/4;
        std::cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
