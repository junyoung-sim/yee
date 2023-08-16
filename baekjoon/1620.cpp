#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N, M;
    std::cin >> N >> M;

    std::string name;
    std::map<std::string, int> map1;
    std::map<int, std::string> map2;

    for(int i = 1; i <= N; i++) {
        std::cin >> name;
        map1[name] = i;
        map2[i] = name;
    }

    std::string x;
    for(int i = 1; i <= M; i++) {
        std::cin >> x;
        if(x[0] - '0' <= 9)
            std::cout << map2[std::stoi(x)] << "\n";
        else
            std::cout << map1[x] << "\n";
    }

    return 0;
}