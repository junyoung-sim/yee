
#include <cstdlib>
#include <iostream>

int main()
{
    int N;
    while(std::cin >> N) {
        int min = 1000000;
        int max = 1;
        for(unsigned int i = 0; i < N; i++) {
            int div;
            std::cin >> div;

            if(div < min)
                min = div;
            if(div > max)
                max = div;
        }

        std::cout << min * max << "\n";
    }
    return 0;
}
