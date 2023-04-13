#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>

struct ID {
    int x = 0;
    int y = 0;
};

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N, M;
    std::cin >> N >> M;

    std::string name;
    std::map<std::string, ID> list;

    for(int i = 0; i < N; i++) {
        std::cin >> name;
        list[name].x = 1;
    }

    for(int i = 0; i < M; i++) {
        std::cin >> name;
        list[name].y = 1;
    }

    int count = 0;
    for(auto l: list)
        count += (l.second.x && l.second.y);
    std::cout << count << "\n";

    for(auto l: list)
        if(l.second.x && l.second.y) std::cout << l.first << "\n";

    return 0;
}