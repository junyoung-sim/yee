#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

bool binary_search(std::vector<std::string> &str, int low, int high, std::string x) {
    int mid = (low + high) / 2;
    if(low > high)
        return false;
    if(x == str[mid])
        return true;
    else if(x > str[mid])
        return binary_search(str, mid+1, high, x);
    else
        return binary_search(str, low, mid-1, x);
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> str(N);
    for(int i = 0; i < N; i++) {
        std::cin >> str[i];
    }

    std::sort(str.begin(), str.end());

    int ans = 0;
    std::string x;
    for(int i = 0; i < M; i++) {
        std::cin >> x;
        ans += binary_search(str, 0, N-1, x);
    }
    std::cout << ans << "\n";

    return 0;
}