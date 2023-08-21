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
    
    int K;
    std::cin >> K;

    int x;
    std::vector<int> log;
    for(int k = 0; k < K; k++) {
        std::cin >> x;
        if(x == 0)
            log.pop_back();
        else
            log.push_back(x);
    }

    int sum = 0;
    for(int &v: log)
        sum += v;
    std::cout << sum << "\n";

    return 0;
}