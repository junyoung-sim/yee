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

bool cmp(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
    if(a.second == b.second) {
        if(a.first.length() == b.first.length())
            return a.first < b.first;
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
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
    
    int N, M;
    std::cin >> N >> M;

    std::string word;
    std::map<std::string, int> list;
    for(int i = 0; i < N; i++) {
        std::cin >> word;
        if(word.length() >= M)
            list[word]++;
    }

    sort(list);

    return 0;
}