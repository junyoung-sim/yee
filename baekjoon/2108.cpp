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

    for(int i = 0; i < N; i++) {
        std::cin >> v[i];
        freq[v[i] + 4000]++;
    }

    double mean = 0;
    for(int &x: v)
        mean += x;
    mean /= N;
    mean += (mean < 0 ? -0.5 : 0.5);
    std::cout << (int)mean << "\n";

    std::sort(v.begin(), v.end());
    std::cout << v[N/2] << "\n";

    v.erase(std::unique(v.begin(), v.end()), v.end());
    int max_freq = *std::max_element(freq.begin(), freq.end());

    int mode = -RAND_MAX;
    for(int &x: v) {
        if(mode == -RAND_MAX && freq[x+4000] == max_freq)
            mode = x;
        else if(mode != -RAND_MAX && freq[x+4000] == max_freq) {
            mode = x;
            break;
        }
    }
    std::cout << mode << "\n";

    std::cout << v[v.size() - 1] - v[0] << "\n";

    return 0;
}