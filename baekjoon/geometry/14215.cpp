#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int a, b, c;
    std::cin >> a >> b >> c;

    int ans = 0;
    int max_len = std::max(a, std::max(b, c));
    
    if(a == max_len) // a < b + c
        ans = b + c + std::min(a, b+c-1);
    else if(b == max_len)
        ans = a + c + std::min(b, a+c-1);
    else
        ans = a + b + std::min(c, a+b-1);
    
    std::cout << ans << "\n";

    return 0;
}