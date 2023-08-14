#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

bool binary_search(std::vector<int> &v, int low, int high, int x) {
    int mid = (high + low) / 2;
    if(low > high)
        return false;
    if(x == v[mid])
        return true;
    else if(x > v[mid])
        return binary_search(v, mid+1, high, x);
    else
        return binary_search(v, low, mid-1, x);
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
    
    std::sort(v.begin(), v.end());

    int M;
    std::cin >> M;

    int x;
    for(int i = 0; i < M; i++) {
        std::cin >> x;
        std::cout << binary_search(v, 0, N-1, x) << " ";
    }

    return 0;
}