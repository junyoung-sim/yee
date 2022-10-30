#include <iostream>
#include <cstdlib>

int N;
int ans = RAND_MAX;

void solve(int n, int count) {
    if(n == 1)
        ans = std::min(count, ans);

    if(n <= 1 || count > ans)
        return;

    if(n % 3 == 0) solve(n / 3, count + 1);
    if(n % 2 == 0) solve(n / 2, count + 1);
    solve(n - 1, count + 1);
}

int main()
{
    std::cin >> N;

    if(N == 1)
        std::cout << "0\n";
    else {
        if(N % 3 == 0) solve(N / 3, 1);
        if(N % 2 == 0) solve(N / 2, 1);
        solve(N - 1, 1);

        std::cout << ans << "\n";
    }

    return 0;
}