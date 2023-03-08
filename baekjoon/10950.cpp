#include <iostream>
#include <cstdlib>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> v(N, std::vector<int>(2,0));
    for(int i = 0; i < N; i++)
        std::cin >> v[i][0] >> v[i][1];
    
    for(int i = 0; i < N; i++)
        std::cout << v[i][0] + v[i][1] << "\n";

    return 0;
}