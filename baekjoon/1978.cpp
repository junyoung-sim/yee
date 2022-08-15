
#include <iostream>

bool is_prime(unsigned int n) {
    if(n == 1 || (n % 2 == 0 && n != 2))
        return false;
    else {
        unsigned int count = 0;
        for(unsigned int k = 1; k <= n; k++)
            count += n % k == 0;
        return count <= 2;
    }
}

int main()
{
    unsigned int N;
    std::cin >> N;

    unsigned int num[N];
    for(unsigned int i = 0; i < N; i++)
        std::cin >> num[i];

    unsigned int prime_count = 0;
    for(unsigned int i = 0; i < N; i++)
        prime_count += is_prime(num[i]);

    std::cout << prime_count << "\n";

    return 0;
}
