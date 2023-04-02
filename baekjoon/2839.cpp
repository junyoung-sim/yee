#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    int ans = RAND_MAX;

    for(int T = 0; T <= N / 3 + (N % 3 != 0); T++)
        for(int F = 0; F <= N / 5 + (N % 5 != 0); F++)
            if(T*3 + F*5 == N) ans = std::min(ans, T+F);
    
    if(ans == RAND_MAX)
        std::cout << "-1\n";
    else
        std::cout << ans << "\n"; 

    return 0;
}