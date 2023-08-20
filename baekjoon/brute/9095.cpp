
#include <iostream>
#include <string>

unsigned int func(unsigned int k, unsigned int sum, unsigned int N) {
    if(sum >= N)
        return sum == N;

    unsigned int total = 0;
    for(unsigned int i = 1; i <= 3; i++)
        total += func(i, sum+i, N);
    return total;
}

int main()
{
    std::string result = "";
    unsigned int T; std::cin >> T;
    for(unsigned int t = 0; t < T; t++) {
        unsigned int N; std::cin >> N;

        unsigned int total = 0;
        for(unsigned int k = 1; k <= 3; k++)
            total += func(k,k,N);
        result += std::to_string(total) + "\n";
    }

    std::cout << result;

    return 0;
}
