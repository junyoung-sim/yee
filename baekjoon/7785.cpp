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
    
    int N;
    std::cin >> N;

    std::string name, status;
    std::map<std::string, int> log;
    std::vector<std::string> names;

    for(int i = 0; i < N; i++) {
        std::cin >> name >> status;
        if(status == "enter") log[name] = 1;
        else log[name] = 0;
    }

    for(auto x: log)
        if(x.second) names.push_back(x.first);
    
    std::sort(names.begin(), names.end());
    for(int i = names.size() - 1; i >= 0; i--)
        std::cout << names[i] << "\n";

    return 0;
}