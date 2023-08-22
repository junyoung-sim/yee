#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <map>
#include <set>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    std::string str;
    std::cin >> str;

    std::set<std::string> set;
    for(int w = 1; w <= str.length(); w++) {
        for(int i = 0; i <= str.length() - w; i++) {
            set.insert(str.substr(i,w));
        }
    }
    std::cout << set.size() << "\n";

    return 0;
}