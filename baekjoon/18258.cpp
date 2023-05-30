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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    std::queue<int> q;
    std::string cmd; int x;
    for(int i = 0; i < N; i++) {
        std::cin >> cmd;
        if(cmd == "push") {
            std::cin >> x;
            q.push(x);
        }
        else if(cmd == "pop") {
            if(q.size() == 0) std::cout << "-1\n";
            else {
                std::cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(cmd == "size")
            std::cout << q.size() << "\n";
        else if(cmd == "empty")
            std::cout << q.empty() << "\n";
        else if(cmd == "front") {
            if(q.size() == 0) std::cout << "-1\n";
            else std::cout << q.front() << "\n";
        }
        else {
            if(q.size() == 0) std::cout << "-1\n";
            else std::cout << q.back() << "\n";
        }
    }

    return 0;
}