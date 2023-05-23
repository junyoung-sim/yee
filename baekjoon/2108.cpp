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

    std::vector<int> v(N);
    std::map<int, int> freq;
    int max_freq = -RAND_MAX;
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        max_freq = std::max(++freq[v[i]], max_freq);
    }
    std::sort(v.begin(), v.end());

    double mean = 0.00;
    for(int &x: v)
        mean += x;
    mean /= N;

    int median = v[N/2];

    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::vector<int> modes;
    for(int &x: v) {
        if(freq[x] == max_freq)
            modes.push_back(x);
        if(modes.size() > 1)
            break;
    }
    int mode = modes[modes.size() != 1];

    int range = v[N-1] - v[0];

    std::cout << std::round(mean) << "\n";
    std::cout << median << "\n";
    std::cout << mode << "\n";
    std::cout << range << "\n";

    return 0;
}