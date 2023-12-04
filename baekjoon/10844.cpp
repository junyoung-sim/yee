#include <iostream>
#include <cstdlib>
#include <vector>

int N;
std::vector<int> digits;
int solutions = 0;

void solve(int i, int t, int n) {
    digits[i] = n;
    if(i == t-1) {
        solutions++;
        return;
    }

    for(int m = 0; m <= 9; m++)
        if(abs(m - digits[i]) == 1) solve(i+1, t, m);
}

int main()
{
    // n:   1 2  3  4  5   6   7   8
    // ans: 9 17 32 61 116 222 424 813

    std::cin >> N;
    long long int dp[N+1][10];
    digits.resize(N);

    for(int n = 1; n <= N; n++) {
        for(int k = 1; k <= 9; k++) {
            if(n <= 5) {
                solve(0, n, k);
                dp[n][k] = solutions % 1000000000;
                solutions = 0;
            }
            else {
                if(k == 1)
                    dp[n][k] = (dp[n-1][k+1] + dp[n-1][9]) % 1000000000;
                else if(k > 1 && k < 9)
                    dp[n][k] = (dp[n-1][k-1] + dp[n-1][k+1]) % 1000000000;
                else
                    dp[n][k] = dp[n-1][k-1] % 1000000000;
            }
        }
    }

    long long int sum = 0;
    for(int k = 1; k <= 9; k++)
        sum += dp[N][k];
    std::cout << sum % 1000000000 << "\n";

    return 0;
}