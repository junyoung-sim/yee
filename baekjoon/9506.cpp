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

    while(std::cin >> N && N != -1) {
        int sum = 0;
        std::vector<int> factor;
        for(int i = 1; i < N; i++) {
            if(N % i == 0) {
                factor.push_back(i);
                sum += i;
            }
        }

        if(sum == N) {
            std::cout << N << " = ";
            for(int i = 0; i < factor.size(); i++) {
                std::cout << factor[i];
                if(i != factor.size() - 1)
                    std::cout << " + ";
            }
            std::cout << "\n";
        }
        else
            std::cout << N << " is NOT perfect.\n";
    }

    return 0;
}