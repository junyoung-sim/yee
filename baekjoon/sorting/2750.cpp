#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    
    int N;
    std::cin >> N;

    std::vector<int> v(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];

    for(int i = 1; i < N; i++) {
        int j = i;
        while(j > 0 && v[j-1] > v[j]) {
            std::swap(v[j-1], v[j]);
            j--;
        }
    }

    for(int val: v)
        std::cout << val << "\n";

    return 0;
}