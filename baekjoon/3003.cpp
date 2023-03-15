#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::vector<int> v = {1, 1, 2, 2, 2, 8};

    int p;
    int i = 0;
    while(std::cin >> p)
        v[i++] -= p;
    
    for(i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";

    return 0;
}