#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

int N;
int T;
std::vector<int> v;

int main()
{
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    std::cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++)
        std::cin >> v[i];
    std::cin >> T;

    int count = 0;
    for(int i = 0; i < N; i++)
        count += (v[i] == T);
    
    std::cout << count << "\n";

    return 0;
}