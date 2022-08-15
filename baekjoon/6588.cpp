
#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> prime(1000000, true); // 1 ~ 1000000
    prime[0] = false;

    unsigned int k = 1;
    while(k < 1000000) {
        unsigned int num = k + 1;
        for(unsigned int i = k + num; i < 1000000; i += num) prime[i] = false;

        while(++k < 1000000 && !prime[k]);
    }

    unsigned int N;
    std::vector<unsigned int> n;
    while(std::cin >> N && N != 0)
        n.push_back(N);

    for(unsigned int &N: n) {
        unsigned int a = 0, b = 0;
        for(unsigned int i = 0; i < N; i++) {
            unsigned int num = i + 1;
            if(prime[i] && prime[N-num-1]) {
                a = i+1;
                b = N-num;
                break;
            }
        }

        if(a != 0)
            std::cout << N << " = " << a << " + " << b << "\n";
        else
            std::cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
