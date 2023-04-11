#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

int binary_search(std::vector<int> &vec, int low, int high, int x) {
    int mid = (low + high) / 2;
    if(low > high)
        return -1;
    if(x == vec[mid])
        return mid;
    else if (x > vec[mid])
        return binary_search(vec, mid+1, high, x);
    else
        return binary_search(vec, low, mid-1, x);
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
    std::sort(vec.begin(), vec.end());
    
    int k;
    std::cin >> k;

    std::cout << binary_search(vec, 0, N-1, k) << "\n";

    return 0;
}