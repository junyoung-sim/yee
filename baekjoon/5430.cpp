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

    int T; std::cin >> T;

    int N;
    std::string cmd, input;
    std::deque<int> dq;

    for(int t = 0; t < T; t++) {
        std::cin >> cmd >> N >> input;
        std::string n = "";
        for(char &x: input) {
            if(x != '[' && x != ']' && x != ',') n += x;
            else {
                if(n != "") {
                    dq.push_back(std::stoi(n));
                    n = "";
                }
            }
        }

        bool front = true; // define which side is "front"
        bool error = false;
        for(char &x: cmd) {
            if(x == 'R') front = !front;
            else {
                error = dq.empty();
                if(error) break;
                if(front) dq.pop_front();
                else dq.pop_back();
            }
        }

        if(error) { std::cout << "error\n"; continue; }

        std::cout << "[";
        while(!dq.empty()) {
            if(front) {
                std::cout << dq.front();
                dq.pop_front();
            }
            else {
                std::cout << dq.back();
                dq.pop_back();
            }
            if(dq.size() > 0) std::cout << ",";
        } std::cout << "]\n";
    }

    return 0;
}