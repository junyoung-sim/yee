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
    }
}

int main()
{
    std::cin >> N;

    // by using solve
    // n:   1 2 3 4 5 6  7  8  9  10
    // ans: 1 2 3 5 8 13 21 34 55 89
    std::vector<int> dynamic = {0, 1, 2};
    for(int n = 3; n <= N; n++) {
        int ans = (dynamic[dynamic.size() - 1] + dynamic[dynamic.size() - 2]) % 10007;
        dynamic.push_back(ans);
    }

    std::cout << dynamic[N] << "\n";

    return 0;
}