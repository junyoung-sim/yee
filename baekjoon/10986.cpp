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

long long int mod[1001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;

    // find number of [i,j] where (s[j] - s[i]) % M == 0 --> s[i] % M == s[j] % M

    long long int x = 0, sum = 0;
    while(N--) {
        std::cin >> x;
        sum += x;
        mod[sum % M]++;
    }

    long long int ans = mod[0];
    for(int i = 0; i <= 1000; i++)
        ans += mod[i] * (mod[i] - 1) / 2;
    
    std::cout << ans << "\n";

    return 0;
}