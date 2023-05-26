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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int N;
    std::cin >> N;

    std::vector<int> stack;
    std::string cmd; int x;

    for(int i = 0; i < N; i++) {
        std::cin >> cmd;
        if(cmd == "push") {
            std::cin >> x;
            stack.push_back(x);
        }
        else if(cmd == "pop") {
            if(stack.size() == 0)
                std::cout << "-1\n";
            else {
                std::cout << stack[stack.size() - 1] << "\n";
                stack.pop_back();
            }
        }
        else if(cmd == "size")
            std::cout << stack.size() << "\n";
        else if(cmd == "empty")
            std::cout << (stack.size() == 0) << "\n";
        else {
            if(stack.size() == 0)
                std::cout << "-1\n";
            else
                std::cout << stack[stack.size() - 1] << "\n";
        }
    }

    return 0;
}