#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int main()
{
    std::vector<int> v(31, 0);

    int n;
    while(std::cin >> n)
        v[n] = 1;
    
    for(int i = 1; i <= 30; i++) {
        if(v[i] == 0)
            std::cout << i << "\n";
    }

    return 0;
}