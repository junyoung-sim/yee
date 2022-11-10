#include <iostream>
#include <vector>

int N;
std::vector<int> blocks;
int solutions = 0;

void solve(int i, int filled, int n) {
    blocks[i] = n;
    filled += n;

    if(filled >= N) {
        solutions += (filled == N);
        return;
    }
    else {
        solve(i+1, filled, 1);
        solve(i+1, filled, 2);
        solve(i+1, filled, 2);
    }
}

int main()
{
    std::cin >> N;

    // by using solve
    // n:   1 2 3 4  5  6  7  8   9   10  11   12
    // ans: 1 3 5 11 21 43 85 171 341 683 1365 2731

    std::vector<int> dynamic = {0, 1, 3};
    int sum = 4;
    for(int n = 3; n <= N; n++) {
        int ans = (n % 2 == 0 ? sum + 2 : sum + 1) % 10007;
        dynamic.push_back(ans);
        sum += ans;
    }

    std::cout << dynamic[N] << "\n";

    return 0;
}