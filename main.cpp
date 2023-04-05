#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int ans = 0;
    for(int i = 1; i <= 500; i++) {
        std::string num = std::to_string(i);
        for(int k = 0; k < num.length(); k++)
            ans += (num[k] == '1');
    }

    std::cout << ans << "\n";

    return 0;
}