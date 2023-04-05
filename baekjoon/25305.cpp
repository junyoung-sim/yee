#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int partition(std::vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for(int j = low; j <= high - 1; j++) {
        if(vec[j] > pivot)
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
    
    int N, K;
    std::cin >> N >> K;

    std::vector<int> vec(N);
    for(int i = 0; i < N; i++)
        std::cin >> vec[i];
    
    quicksort(vec, 0, N-1);

    std::cout << vec[K-1] << "\n";

    return 0;
}