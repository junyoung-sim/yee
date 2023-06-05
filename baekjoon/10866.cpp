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
#include <stack>
#include <queue>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    std::cin >> N;

    std::deque<int> d;
    for(int i = 0; i < N; i++) {
        int x;
        std::string cmd;
        std::cin >> cmd;

        if(cmd == "push_front") {
            std::cin >> x;
            d.push_front(x);
        }
        else if(cmd == "push_back") {
            std::cin >> x;
            d.push_back(x);
        }
        else if(cmd == "size") std::cout << d.size() << "\n";
        else if(cmd == "empty") std::cout << d.empty() << "\n";
        else {
            if(d.empty()) { std::cout << "-1\n"; continue; }
            if(cmd == "pop_front") { std::cout << d.front() << "\n"; d.pop_front(); }
            else if(cmd == "pop_back") { std::cout << d.back() << "\n"; d.pop_back(); }
            else if(cmd == "front") std::cout << d.front() << "\n";
            else std::cout << d.back() << "\n";
        }
    }

    return 0;
}