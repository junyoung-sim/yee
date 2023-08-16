#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

int partition(std::vector<std::vector<int>> &v, int low, int high) {
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(v[j][1] < v[high][1] || v[j][1] == v[high][1] && v[j][0] < v[high][0])
            std::swap(v[++i], v[j]);
    }
    std::swap(v[++i], v[high]);
    return i;
}

void quicksort(std::vector<std::vector<int>> &v, int low, int high) {
    if(low < high) {
        int p = partition(v, low, high);
        quicksort(v, low, p-1);
        quicksort(v, p+1, high);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> v(N, std::vector<int>(2));
    for(int i = 0; i < N; i++)
        std::cin >> v[i][0] >> v[i][1];
    
    std::default_random_engine seed;
    std::shuffle(v.begin(), v.end(), seed);

    quicksort(v, 0, N-1);

    for(int i = 0; i < N; i++)
        std::cout << v[i][0] << " " << v[i][1] << "\n";

    return 0;
}