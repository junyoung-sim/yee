#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

int N = 0, ans = 0;
std::vector<int> chess; // index = row, value = col

bool check(int n) {
    for(int i = 0; i < n; i++)
        if(chess[i] == chess[n] || n - i == abs(chess[n] - chess[i])) return false;
    return true;
}

void nqueen(int n) {
    if(n == N) {
        ans++;
        return;
    }
    for(int i = 0; i < N; i++) {
        chess[n] = i;
        if(check(n))
            nqueen(n+1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> N;
    chess.resize(N);

    nqueen(0);
    std::cout << ans << "\n";

    return 0;
}