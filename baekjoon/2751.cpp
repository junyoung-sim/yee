#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

int partition(std::vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(vec[j] < pivot)
            std::swap(vec[++i], vec[j]);
    }
    std::swap(vec[++i], vec[high]);
    return i;
}

void quicksort(std::vector<int> &vec, int low, int high) {
    if(low < high) {
        int p = partition(vec, low, high);
        quicksort(vec, low, p-1);
        quicksort(vec, p+1, high);
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    
    std::default_random_engine seed;
    std::shuffle(v.begin(), v.end(), seed);
    quicksort(v, 0, N-1);

    for(int &val: v)
        std::cout << val << "\n";

    return 0;
}