#include <bits/stdc++.h>
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
    std::cin >> std::ws;
    
    std::vector<std::string> input(N);
    for(int i = 0; i < N; i++)
        std::getline(std::cin, input[i]);

    for(std::string &str: input) {
        std::stack<char> s;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != ' ') s.push(str[i]);
            if(str[i] == ' ' || i == str.length() - 1) {
                while(!s.empty()) {
                    std::cout << s.top();
                    s.pop();
                }
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    return 0;
}