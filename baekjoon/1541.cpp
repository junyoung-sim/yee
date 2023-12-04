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

    std::string str;
    std::cin >> str;

    std::string num = "";
    bool minus = false;
    int ans = 0;

    for(int i = 0; i <= str.length(); i++) {
        if(str[i] - '0' < 0 || i == str.length()) {
            if(minus) ans -= std::stoi(num);
            else ans += std::stoi(num);
            num = "";
        }
        else num += str[i];

        if(!minus) minus = (str[i] == '-');
    }

    std::cout << ans << "\n";

    return 0;
}