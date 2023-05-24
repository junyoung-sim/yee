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

bool cmp(std::pair<std::string, int> &x, std::pair<std::string, int> &y) {
    if(x.second == y.second) {
        if(x.first.length() == y.first.length())
            return x.first < y.first;
        return x.first.length() < y.first.length();
    }
    return x.second > y.second;
}

void sort(std::map<std::string, int> &list) {
    std::vector<std::pair<std::string, int>> v;
    for(auto &x: list)
        v.push_back(x);
    
    std::sort(v.begin(), v.end(), cmp);

    for(auto &x: v)
        std::cout << x.first << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    std::string str;
    std::map<std::string, int> list;
    for(int i = 0; i < N; i++) {
        std::cin >> str;
        list[str]++;
    }

    sort(list); // (1) frequency (2) length (3) alphabetic order

    return 0;
}