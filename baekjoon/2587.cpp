#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<int> v(5);
    for(int i = 0; i < 5; i++)
        std::cin >> v[i];

    for(int i = 1; i < 5; i++) {
        int j = i;
        while(j > 0 && v[j-1] > v[j]) {
            std::swap(v[j-1], v[j]);
            j--;
        }
    }

    int mean = 0;
    for(int i = 0; i < 5; i++)
        mean += v[i];
    mean /= 5;

    std::cout << mean << "\n";
    std::cout << v[2] << "\n";

    return 0;
}