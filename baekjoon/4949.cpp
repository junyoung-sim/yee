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

bool vps(std::string str) {
    std::vector<char> close;
    for(char &x: str) {
        if(x == '(') close.push_back(')');
        if(x == '[') close.push_back(']');
        if(x == ')' || x == ']') {
            if(close.size() != 0 && x == close[close.size() - 1]) close.pop_back();
            else return false;
        }
    }
    return (close.size() == 0);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    while(std::getline(std::cin, str) && str != ".") {
        if(vps(str)) std::cout << "yes\n";
        else std::cout << "no\n";
    }

    return 0;
}