#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::string num;
    std::cin >> num;

    std::vector<int> count(10, 0);
    for(char ch: num)
        count[ch - '0']++;

    for(int i = 9; i >= 0; i--)
        for(int j = 0; j < count[i]; j++)
            std::cout << i;
    std::cout << "\n";

    return 0;
}