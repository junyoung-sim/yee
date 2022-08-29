#include <iostream>
#include <vector>

int N;
std::vector<int> T;
std::vector<int> P;

int ans = 0;

void func(int i, int sum) {
    if(i + T[i] - 1 == N)
        ans = std::max(sum + P[i], ans);
    else if(i + T[i] - 1 > N)
        ans = std::max(sum, ans);
    else {
        sum += P[i];
        for(int k = i + T[i]; k <= N; k++)
            func(k, sum);
    }
}

int main()
{
    std::cin >> N;
    T.resize(N+1);
    P.resize(N+1);
    for(int i = 1; i <= N; i++)
        std::cin >> T[i] >> P[i];

    for(int i = 1; i <= N; i++)
        func(i, 0);

    std::cout << ans << "\n";

    return 0;
}
