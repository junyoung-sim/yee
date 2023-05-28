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

    std::string str;
    for(int i = 0; i < N; i++) {
        std::cin >> str;
        int left = 0;
        for(int k = 0; k < str.length(); k++) {
            left += (str[k] == '(');
            left -= (str[k] == ')');

            if(left < 0) break;
        }
        if(left == 0) std::cout << "YES\n";
        else std::cout << "NO\n";
    }

    return 0;
}