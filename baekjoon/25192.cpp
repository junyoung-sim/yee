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

    std::string input;
    std::map<std::string, bool> log;
    int ans = 0;

    for(int i = 0; i < N; i++) {
        std::cin >> input;
        if(input == "ENTER")
            log.clear();
        else {
            if(log[input]) continue;

            log[input] = true;
            ans++;
        }
    }

    std::cout << ans << "\n";

    return 0;
}