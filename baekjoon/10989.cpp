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

    std::vector<int> count(10001, 0);

    int k;
    for(int i = 0; i < N; i++) {
        std::cin >> k;
        count[k]++;
    }

    for(int i = 1; i <= 10000; i++)
        for(int j = 0; j < count[i]; j++)
            std::cout << i << "\n";

    return 0;
}