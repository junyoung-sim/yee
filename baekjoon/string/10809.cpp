#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::string str;
    std::cin >> str;

    std::vector<int> v(26, -1);
    for(int i = 0; i < str.length(); i++) {
        int ascii = (int)str[i] - 97;
        if(v[ascii] == -1)
            v[ascii] = i;
    }

    for(int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    return 0;
}