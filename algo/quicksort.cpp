#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int partition(std::vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        // move all values smaller than pivot to the left
        if(vec[j] < pivot)
            std::swap(vec[++i], vec[j]);
    }
    // move all values larger than pivot to the right
    std::swap(vec[++i], vec[high]);
    return i;
}

void quicksort(std::vector<int> &vec, int low, int high) {
    if(low < high) {
        int p = partition(vec, low, high); // partition index
        quicksort(vec, low, p-1); // left of partition index
        quicksort(vec, p+1, high); // right of partition index
    }
}

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    for(int i = 0; i < N; i++)
        std::cin >> vec[i];
    
    // shuffle data to prevent worst case runtime
    std::default_random_engine seed;
    std::shuffle(vec.begin(), vec.end(), seed);

    quicksort(vec, 0, N-1);

    for(int &val: vec)
        std::cout << val << " ";
    std::cout << "\n";

    return 0;
}