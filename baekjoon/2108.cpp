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
    std::vector<int> freq(8001, 0); // -4000 ~ 4000

    double sum = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        sum += v[i];   
        freq[v[i] + 4000]++;
    }
    std::sort(v.begin(), v.end());

    int t; int max_freq = 0;
    for(int i = 0; i <= 8000; i++) {
        if(freq[i] > max_freq) {
            t = i;
            max_freq = freq[i];
        }
    }
    for(int i = t + 1; i <= 8000; i++) {
        if(freq[i] == max_freq) {
            t = i;
            break;
        }
    }

    std::cout << std::round(sum / N) << "\n"; // mean
    std::cout << v[(N-1)/2] << "\n"; // median
    std::cout << t - 4000 << "\n";
    std::cout << v[N-1] - v[0] << "\n"; // range

    return 0;
}